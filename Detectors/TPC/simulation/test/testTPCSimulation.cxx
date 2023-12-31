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

/// \file testTPCSimulation.cxx
/// \brief This task tests several small components of the TPC simulation
/// \author Andi Mathis, TU München, andreas.mathis@ph.tum.de

#define BOOST_TEST_MODULE Test TPC Simulation
#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "TPCSimulation/Point.h"
#include "MathUtils/Cartesian.h"

template <typename T>
using Point3D = o2::math_utils::Point3D<T>;

namespace o2
{
namespace tpc
{

/// \brief Trivial test of the initialization of a Point and its getters
/// Precision: 1E-12 %
BOOST_AUTO_TEST_CASE(Point_test)
{
  Point testpoint(2.f, 3.f, 4.f, 5.f, 6, 7, 8);
  BOOST_CHECK_CLOSE(testpoint.GetX(), 2., 1E-12);
  BOOST_CHECK_CLOSE(testpoint.GetY(), 3., 1E-12);
  BOOST_CHECK_CLOSE(testpoint.GetZ(), 4., 1E-12);
  BOOST_CHECK_CLOSE(testpoint.GetTime(), 5., 1E-12);
  BOOST_CHECK_CLOSE(testpoint.GetEnergyLoss(), 6, 1E-12);
  BOOST_CHECK_CLOSE(testpoint.GetTrackID(), 7., 1E-12);
  BOOST_CHECK_CLOSE(testpoint.GetDetectorID(), 8., 1E-12);
}

} // namespace tpc
} // namespace o2
