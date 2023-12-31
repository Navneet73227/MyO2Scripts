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

/// \file preclusters-to-clusters-GEM-workflow.cxx
/// \brief This is an executable that runs the GEM MLEM cluster finder via DPL.
///
/// \author Philippe Pillot, Subatech

/* ???
#include "Framework/runDataProcessing.h"

#include "MCHWorkflow/ClusterFinderGEMSpec.h"

using namespace o2::framework;

WorkflowSpec defineDataProcessing(const ConfigContext&)
{
  return WorkflowSpec{o2::mch::getClusterFinderGEMSpec()};
}
*/

#include "CommonUtils/ConfigurableParam.h"
#include "ClusterFinderGEMSpec.h"

using namespace o2::framework;

// we need to add workflow options before including Framework/runDataProcessing
void customize(std::vector<ConfigParamSpec>& workflowOptions)
{
  workflowOptions.emplace_back("configKeyValues", VariantType::String, "",
                               ConfigParamSpec::HelpString{"Semicolon separated key=value strings"});
}

#include "Framework/runDataProcessing.h"

WorkflowSpec defineDataProcessing(const ConfigContext& configcontext)
{
  o2::conf::ConfigurableParam::updateFromString(configcontext.options().get<std::string>("configKeyValues"));
  return WorkflowSpec{o2::mch::getClusterFinderGEMSpec()};
}
