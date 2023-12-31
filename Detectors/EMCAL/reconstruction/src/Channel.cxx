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
#include "EMCALReconstruction/Channel.h"

using namespace o2::emcal;

int Channel::getBranchIndex() const
{
  if (mHardwareAddress == -1) {
    throw HardwareAddressError();
  }
  return getBranchIndexFromHwAddress(mHardwareAddress);
}

int Channel::getFECIndex() const
{
  if (mHardwareAddress == -1) {
    throw HardwareAddressError();
  }
  return getFecIndexFromHwAddress(mHardwareAddress);
}

Int_t Channel::getAltroIndex() const
{
  if (mHardwareAddress == -1) {
    throw HardwareAddressError();
  }
  return getAltroIndexFromHwAddress(mHardwareAddress);
}

Int_t Channel::getChannelIndex() const
{
  if (mHardwareAddress == -1) {
    throw HardwareAddressError();
  }
  return getChannelIndexFromHwAddress(mHardwareAddress);
}

Bunch& Channel::createBunch(uint8_t bunchlength, uint8_t starttime)
{
  mBunches.emplace_back(bunchlength, starttime);
  return mBunches.back();
}