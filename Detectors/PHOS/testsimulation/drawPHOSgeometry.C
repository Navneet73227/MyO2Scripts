#if !defined(__CLING__) || defined(__ROOTCLING__)
#include "DetectorsPassive/Cave.h"
#include "DetectorsPassive/FrameStructure.h"
#include "FairRunSim.h"
#include <FairRootFileSink.h>
#include "PHOSSimulation/Detector.h"
#include "TGeoManager.h"
#include "TROOT.h"
#include "TString.h"
#include "TSystem.h"

#include <boost/program_options.hpp>
#include <iomanip>
#include <iostream>
#endif

void drawPHOSgeometry()
{
  // minimal macro to test setup of the geometry

  TString dir = getenv("VMCWORKDIR");
  TString geom_dir = dir + "/Detectors/Geometry/";
  gSystem->Setenv("GEOMPATH", geom_dir.Data());

  TString tut_configdir = dir + "/Detectors/gconfig";
  gSystem->Setenv("CONFIG_DIR", tut_configdir.Data());

  // Create simulation run
  FairRunSim* run = new FairRunSim();
  run->SetSink(new FairRootFileSink("foo.root")); // Output file
  run->SetName("TGeant3");        // Transport engine
  // Create media
  run->SetMaterials("media.geo"); // Materials

  // Create geometry

  o2::passive::Cave* cave = new o2::passive::Cave("CAVE");
  cave->SetGeometryFileName("cave.geo");
  run->AddModule(cave);

  // o2::passive::FrameStructure* frame = new o2::passive::FrameStructure("Frame", "Frame");
  // run->AddModule(frame);

  o2::phos::Detector* phos = new o2::phos::Detector(kTRUE);
  run->AddModule(phos);

  run->Init();
  {
    const TString ToHide = "cave";

    TObjArray* lToHide = ToHide.Tokenize(" ");
    TIter* iToHide = new TIter(lToHide);
    TObjString* name;
    while ((name = (TObjString*)iToHide->Next()))
      gGeoManager->GetVolume(name->GetName())->SetVisibility(kFALSE);

    TString ToShow =
      "PHOS PHOH PHOC PSTR PCEL PWRA PXTL PPIN PREA PSUP PSHO PTII PTIH PAGA PAGH PCOR PCOH PTIO PIOH PCOL PCLH PFGC "
      "PWAR PWTI PCA1 PBE1 PCA2 PBE2 PFRX PFRZ PFG1 PFG2 PFG3 PFG4 PAFE PEMC PEMH PCPV PCPC PCPD PCPF PCPG PCPQ PCP1 "
      "PCF1 PCF2";
    // Support geometry
    //   TString ToShow =
    //      "PSTR PCEL PWRA PXTL PPIN PREA PSUP PSHO PTII PTIH PAGA PAGH PCOR PCOH PTIO PIOH PCOL PCLH PFGC PWAR PWTI
    //      PCA1 PBE1 PCA2 PBE2 PFRX PFRZ PFG1 PFG2 PFG3 PFG4 PAFE PEMC PEMH PCPV PCPC PCPD PCPF PCPG PCPQ PCP1 PCF1
    //      PCF2 PCRA PCRE PWHE";

    TObjArray* lToShow = ToShow.Tokenize(" ");
    TIter* iToShow = new TIter(lToShow);
    while ((name = (TObjString*)iToShow->Next())) {
      if (gGeoManager->GetVolume(name->GetName()))
        gGeoManager->GetVolume(name->GetName())->SetVisibility(kTRUE);
      else
        printf("No volume <%s>\n", name->GetName());
    }

    const TString ToTrans = ""; // PHOS PHOH PHOC";

    TObjArray* lToTrans = ToTrans.Tokenize(" ");
    TIter* iToTrans = new TIter(lToTrans);
    while ((name = (TObjString*)iToTrans->Next())) {
      if (gGeoManager->GetVolume(name->GetName()))
        gGeoManager->GetVolume(name->GetName())->SetTransparency(50);
      else
        printf("No volume <%s>\n", name->GetName());
    }
  }

  gGeoManager->GetListOfVolumes()->ls();
  gGeoManager->CloseGeometry();
  gGeoManager->SetVisLevel(0); // (default) TGeo calculate number of levels to draw
                               // gGeoManager->SetVisLevel(5); // User defines depth of levels to draw
  // gGeoManager->SetVisLevel(1); // (default) do not draw contained, inner parts only

  gGeoManager->GetTopVolume()->Draw("ogl");

  // gGeoManager->Export("PHOSgeometry.root");
}
