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
#include "SimpleResourceManager.h"
#include "Framework/ComputingResource.h"
#include <fmt/format.h>
#include <exception>
#include <stdexcept>

namespace o2::framework
{

/// The simplest implementation of this allocates mMaxPorts ports starting from
/// the mInitialPort. For now we still consider everything running on a single
/// machine.
std::vector<ComputingOffer> SimpleResourceManager::getAvailableOffers()
{
  std::vector<ComputingOffer> result;

  for (auto& resource : mResources) {
    if (resource.cpu < 0.01) {
      continue;
    }
    if (resource.memory < 0.01) {
      continue;
    }
    if (resource.usedPorts == (resource.lastPort - resource.startPort + 1)) {
      continue;
    }
    ComputingOffer offer;
    offer.cpu = resource.cpu;
    offer.memory = resource.memory;
    offer.hostname = resource.hostname;
    offer.startPort = resource.startPort + resource.usedPorts;
    offer.rangeSize = (resource.lastPort - resource.startPort) - resource.usedPorts;
    result.push_back(offer);
  }
  return result;
}

void SimpleResourceManager::notifyAcceptedOffer(ComputingOffer const& offer)
{
  bool resourceFound = false;
  for (auto& resource : mResources) {
    if (resource.hostname != offer.hostname) {
      continue;
    }
    if (resource.startPort > offer.startPort) {
      continue;
    }
    if (resource.lastPort < offer.startPort + offer.rangeSize) {
      continue;
    }
    resourceFound = true;
    resource.cpu -= offer.cpu;
    resource.memory -= offer.memory;
    resource.usedPorts += offer.rangeSize;
    break;
  }

  if (resourceFound == false) {
    std::string resources = "Available resources:\n";
    for (auto& resource : mResources) {
      resources += fmt::format("- (host:{}, cpu:{}, memory:{}, ports:{}-{})\n", resource.hostname.c_str(), resource.cpu, resource.memory, resource.startPort, resource.lastPort);
    }
    throw std::runtime_error(fmt::format("Could not match offer (host:{}, cpu:{}, mem:{}, ports:{}) to original resource.\n"
                                         "Most likely you need to declare more resources via --resources or reduce the number of devices.",
                                         offer.hostname, offer.cpu, offer.memory, offer.rangeSize) +
                             resources);
  }
}

} // namespace o2::framework
