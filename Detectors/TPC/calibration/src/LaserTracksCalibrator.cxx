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

#include <fmt/format.h>

#include "TPCCalibration/LaserTracksCalibrator.h"

using namespace o2::tpc;

void LaserTracksCalibrator::initOutput()
{
  mCalibPerSlot.clear();
}

//______________________________________________________________________________
void LaserTracksCalibrator::finalizeSlot(Slot& slot)
{
  auto& calibLaser = *slot.getContainer();
  calibLaser.finalize();
  calibLaser.print();

  mCalibPerSlot.emplace_back(calibLaser.getCalibData());
}

//______________________________________________________________________________
LaserTracksCalibrator::Slot& LaserTracksCalibrator::emplaceNewSlot(bool front, TFType tstart, TFType tend)
{
  auto& cont = getSlots();
  auto& slot = front ? cont.emplace_front(tstart, tend) : cont.emplace_back(tstart, tend);
  slot.setContainer(std::make_unique<CalibLaserTracks>());
  auto& calibLaser = *slot.getContainer();
  //calibLaser.setTFtimes(tstart, tend);

  if (mWriteDebug) {
    calibLaser.setWriteDebugTree(mWriteDebug);
    calibLaser.setDebugOutputName(fmt::format("CalibLaserTracks_debug_{}_{}.root", tstart, tend));
  }

  return slot;
}
