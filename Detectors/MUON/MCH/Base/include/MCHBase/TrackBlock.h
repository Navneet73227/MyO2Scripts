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

/// \file TrackBlock.h
/// \brief Definition of the MCH track parameters minimal structure
///
/// \author Philippe Pillot, Subatech

#ifndef O2_MCH_TRACKBLOCK_H_
#define O2_MCH_TRACKBLOCK_H_

#include <iostream>

namespace o2
{
namespace mch
{

/// track parameters minimal structure
struct TrackParamStruct {
  double x;   ///< track position along x
  double y;   ///< track position along y
  double z;   ///< track position along z
  double px;  ///< track momentum along x
  double py;  ///< track momentum along y
  double pz;  ///< track momentum along z
  short sign; ///< track sign
};

std::ostream& operator<<(std::ostream& stream, const TrackParamStruct& trackParam);

} // namespace mch
} // namespace o2

#endif // O2_MCH_TRACKBLOCK_H_
