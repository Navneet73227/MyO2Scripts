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

/// @file   ClusterReaderSpec.h

#ifndef O2_ITSMFT_CLUSTERREADER
#define O2_ITSMFT_CLUSTERREADER

#include "TFile.h"
#include "TTree.h"

#include "Framework/DataProcessorSpec.h"
#include "Framework/Task.h"
#include "Headers/DataHeader.h"
#include "DataFormatsITSMFT/CompCluster.h"
#include "SimulationDataFormat/MCCompLabel.h"
#include "SimulationDataFormat/MCTruthContainer.h"
#include "DataFormatsITSMFT/ROFRecord.h"
#include "DetectorsCommonDataFormats/DetID.h"

using namespace o2::framework;

namespace o2
{
namespace itsmft
{

class ClusterReader : public Task
{
 public:
  ClusterReader() = delete;
  ClusterReader(o2::detectors::DetID id, bool useMC, bool usePatterns = true, bool triggers = true);
  ~ClusterReader() override = default;
  void init(InitContext& ic) final;
  void run(ProcessingContext& pc) final;

 protected:
  void connectTree(const std::string& filename);

  std::vector<o2::itsmft::ROFRecord> mClusROFRec, *mClusROFRecPtr = &mClusROFRec;
  std::vector<o2::itsmft::CompClusterExt> mClusterCompArray, *mClusterCompArrayPtr = &mClusterCompArray;
  std::vector<unsigned char> mPatternsArray, *mPatternsArrayPtr = &mPatternsArray;
  o2::dataformats::MCTruthContainer<o2::MCCompLabel> mClusterMCTruth, *mClusterMCTruthPtr = &mClusterMCTruth;
  std::vector<o2::itsmft::MC2ROFRecord> mClusMC2ROFs, *mClusMC2ROFsPtr = &mClusMC2ROFs;

  o2::header::DataOrigin mOrigin = o2::header::gDataOriginInvalid;

  std::unique_ptr<TFile> mFile;
  std::unique_ptr<TTree> mTree;

  bool mUseMC = true;     // use MC truth
  bool mUsePatterns = true; // send patterns
  bool mTriggerOut = true;  // send dummy triggers vector

  std::string mDetName = "";
  std::string mDetNameLC = "";
  std::string mFileName = "";
  std::string mClusTreeName = "o2sim";
  std::string mClusROFBranchName = "ClustersROF";
  std::string mClusterPattBranchName = "ClusterPatt";
  std::string mClusterCompBranchName = "ClusterComp";
  std::string mClustMCTruthBranchName = "ClusterMCTruth";
  std::string mClustMC2ROFBranchName = "ClustersMC2ROF";
};

class ITSClusterReader : public ClusterReader
{
 public:
  ITSClusterReader(bool useMC = true, bool usePatterns = true, bool triggerOut = true)
    : ClusterReader(o2::detectors::DetID::ITS, useMC, usePatterns, triggerOut)
  {
    mOrigin = o2::header::gDataOriginITS;
  }
};

class MFTClusterReader : public ClusterReader
{
 public:
  MFTClusterReader(bool useMC = true, bool usePatterns = true, bool triggerOut = true)
    : ClusterReader(o2::detectors::DetID::MFT, useMC, usePatterns, triggerOut)
  {
    mOrigin = o2::header::gDataOriginMFT;
  }
};

/// create a processor spec
/// read ITS/MFT cluster data from a root file
framework::DataProcessorSpec getITSClusterReaderSpec(bool useMC = true, bool usePatterns = true, bool useTriggers = true);
framework::DataProcessorSpec getMFTClusterReaderSpec(bool useMC = true, bool usePatterns = true, bool useTriggers = true);

} // namespace itsmft
} // namespace o2

#endif /* O2_ITSMFT_CLUSTERREADER */
