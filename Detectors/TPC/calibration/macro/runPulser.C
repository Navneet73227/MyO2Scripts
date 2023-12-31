// Copyright 2019-2020 CERN and copyright holders of ALICE O2.
// See https://alice-o2.web.cern.ch/copyright for details of the copyright holders.
// All rights not expressly granted are reserved.
//
// This software is distributed under the terms of the GNU General Public
// License v3 (GPL Version 3), copied verbatim in the file "COPYING".
//
// In applying this license CERN does not waive the privileges and immunities
// granted to it by virtue of its status as an Intergovernmental Organization
// or submit itself to any jurisdiction.

#if !defined(__CLING__) || defined(__ROOTCLING__)
#include <iostream>
#include <vector>
#include <string_view>
#include "TFile.h"
#include "TPCCalibration/CalibPulser.h"
#include "TPCCalibration/CalibRawBase.h"
#endif

void runPulser(std::vector<std::string_view> fileInfos, TString outputFileName = "", Int_t nevents = 100,
               Int_t adcMin = 0, Int_t adcMax = 1100,
               Int_t firstTimeBin = 0, Int_t lastTimeBin = 500,
               TString pedestalAndNoiseFile = "",
               uint32_t verbosity = 0, uint32_t debugLevel = 0, int type = 0)
{
  using namespace o2::tpc;
  // ===| set up calibration class |============================================
  CalibPulser calib;
  calib.setADCRange(adcMin, adcMax);
  calib.setTimeBinRange(firstTimeBin, lastTimeBin);
  calib.setDebugLevel();
  //calib.setQtotBinning(140, 22, 302);
  calib.setQtotBinning(500, 10, 1010);
  if (type == 0) {
    calib.setWidthBinning(100, 0.1, 2.1);
  } else if (type == 1) {
    calib.setQtotBinning(150, 2, 302);
    calib.setMinQtot(8);
    calib.setMinQmax(6);
    calib.setMaxTimeBinRange(6);
  }
  //calib.setDebugLevel(debugLevel);

  // ===| load pedestal if requested |==========================================
  if (!pedestalAndNoiseFile.IsNull()) {
    CalDet<float> dummy;
    CalDet<float>* pedestal = nullptr;
    CalDet<float>* noise = nullptr;
    TFile f(pedestalAndNoiseFile);
    if (!f.IsOpen() || f.IsZombie()) {
      std::cout << "Could not open noise and pedestal file " << pedestalAndNoiseFile << "\n";
      return;
    }

    f.GetObject("Pedestals", pedestal);
    f.GetObject("Noise", noise);
    if (!(pedestal && noise)) {
      std::cout << "Could not load pedestal and nosie from file " << pedestalAndNoiseFile << "\n";
      return;
    }
    calib.setPedestalAndNoise(pedestal, noise);
  }

  CalibRawBase::ProcessStatus status = CalibRawBase::ProcessStatus::Ok;

  for (const auto& fileInfo : fileInfos) {
    calib.setupContainers(fileInfo.data(), verbosity, debugLevel);

    for (Int_t i = 0; i < nevents; ++i) {
      status = calib.processEvent(i);
      std::cout << "Processing event " << i << " with status " << int(status) << '\n';
      if (status == CalibRawBase::ProcessStatus::LastEvent) {
        break;
      }
    }
  }
  calib.analyse();

  std::cout << "Number of processed events: " << calib.getNumberOfProcessedEvents() << '\n';
  std::cout << "Status: " << int(status) << '\n';
  if (outputFileName.IsNull()) {
    outputFileName = "Pulser.root";
  }

  calib.dumpToFile(outputFileName.Data());

  std::cout << "To display the Pulsers run: root.exe $calibMacroDir/drawPulser.C'(\"" << outputFileName << "\")'\n";
}
