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

/// \class CalibParams
/// \brief CCDB container for the full set of CPV calibration coefficients
/// \author Dmitri Peresunko, RRC Kurchatov institute
/// \since Aug. 1, 2019
///
///

#ifndef CPV_CALIBPARAMS_H
#define CPV_CALIBPARAMS_H

#include <array>
#include "TObject.h"
#include "CPVBase/Geometry.h"

class TH2;

namespace o2
{

namespace cpv
{

class CalibParams
{
 public:
  /// \brief Constructor
  CalibParams() = default;

  /// \brief Constructor for tests
  CalibParams(short test);

  /// \brief Destructor
  ~CalibParams() = default;

  /// \brief Get High Gain energy calibration coefficients
  /// \param cellID Absolute ID of cell
  /// \return high gain energy calibration coefficient of the cell
  float getGain(unsigned short cellID) const { return mGainCalib[cellID]; }

  /// \brief Set High Gain energy calibration coefficient
  /// \param cellID Absolute ID of cell
  /// \param c is the calibration coefficient
  void setGain(unsigned short cellID, float c)
  {
    if (cellID < o2::cpv::Geometry::kNCHANNELS) {
      mGainCalib[cellID] = c;
    }
  }

  /// \brief Set High Gain energy calibration coefficients for one module in the form of 2D histogram
  /// \param 2D(64,56) histogram with calibration coefficients
  /// \param module number
  /// \return Is successful
  bool setGain(TH2* h, short module);

 private:
  static constexpr short NCHANNELS = 23040; ///< Number of channels starting from 0
  std::array<float, NCHANNELS> mGainCalib;  ///< Container for the gain calibration coefficients
  ClassDefNV(CalibParams, 2);
};

} // namespace cpv

} // namespace o2
#endif
