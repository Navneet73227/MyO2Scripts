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

#ifndef ALICEO2_FV0_DIGITIZATION_CONSTANT
#define ALICEO2_FV0_DIGITIZATION_CONSTANT

namespace o2::fv0
{
struct DigitizationConstant {
  static constexpr int NCELLSA = 40;                                         // number of scintillator cells
  static constexpr float INV_CHARGE_PER_ADC = 1. / 0.6e-12;                  // charge conversion
  static constexpr float TIME_PER_TDCCHANNEL = 0.01302;                      // time conversion from TDC channels to ns
  static constexpr float INV_TIME_PER_TDCCHANNEL = 1. / TIME_PER_TDCCHANNEL; // time conversion from ns to TDC channels
  static constexpr float N_PHOTONS_PER_MEV = 10400;                          // average #photons generated per 1 MeV of deposited energy
};
} // namespace o2::fv0
#endif
