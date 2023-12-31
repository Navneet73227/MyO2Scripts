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

/// @file   TOFCalClusInfoWriterSpec.cxx

#include "TOFWorkflowIO/TOFCalClusInfoWriterSpec.h"
#include "DPLUtils/MakeRootTreeWriterSpec.h"
#include "DataFormatsTOF/CalibInfoCluster.h"
#include "DataFormatsTOF/CosmicInfo.h"

using namespace o2::framework;

namespace o2
{
namespace tof
{
template <typename T>
using BranchDefinition = MakeRootTreeWriterSpec::BranchDefinition<T>;
using OutputType = std::vector<o2::tof::CalibInfoCluster>;
using OutputCosmicType = std::vector<o2::tof::CosmicInfo>;
using OutputTrackType = std::vector<o2::tof::CalibInfoTrackCl>;
using OutputTrackSizeType = std::vector<int>;
using namespace o2::header;

DataProcessorSpec getTOFCalClusInfoWriterSpec(bool isCosmics)
{
  // Spectators for logging
  auto logger = [](OutputType const& indata) {
    LOG(debug) << "RECEIVED CLUS CAL INFO SIZE " << indata.size();
  };
  auto loggerCosmics = [](OutputCosmicType const& indata) {
    LOG(debug) << "RECEIVED COSMICS INFO SIZE " << indata.size();
  };
  auto loggerTracks = [](OutputTrackType const& indata) {
    LOG(debug) << "RECEIVED COSMICS TRACK CLUSTERS INFO SIZE " << indata.size();
  };
  auto loggerTracksSize = [](OutputTrackSizeType const& indata) {
    LOG(debug) << "RECEIVED COSMICS TRACK INFO SIZE " << indata.size();
  };

  return MakeRootTreeWriterSpec("TOFCalClusInfoWriter",
                                "tofclusCalInfo.root",
                                "o2sim",
                                BranchDefinition<OutputType>{InputSpec{"clusters", gDataOriginTOF, "INFOCALCLUS", 0},
                                                             "TOFClusterCalInfo",
                                                             "tofclusters-branch-name",
                                                             1,
                                                             logger},
                                BranchDefinition<OutputCosmicType>{InputSpec{"cosmics", gDataOriginTOF, "INFOCOSMICS", 0},
                                                                   "TOFCosmics",
                                                                   "tofcosmics-branch-name",
                                                                   (isCosmics ? 1 : 0),
                                                                   loggerCosmics},
                                BranchDefinition<OutputTrackType>{InputSpec{"tracks", gDataOriginTOF, "INFOTRACKCOS", 0},
                                                                  "TOFTracks",
                                                                  "toftracks-branch-name",
                                                                  (isCosmics ? 1 : 0),
                                                                  loggerTracks},
                                BranchDefinition<OutputTrackSizeType>{InputSpec{"tracksize", gDataOriginTOF, "INFOTRACKSIZE", 0},
                                                                      "TOFTracksSize",
                                                                      "toftrackssize-branch-name",
                                                                      (isCosmics ? 1 : 0),
                                                                      loggerTracksSize})();
}
} // namespace tof
} // namespace o2
