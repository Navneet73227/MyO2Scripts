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

#include "DetectorsCommonDataFormats/DetMatrixCache.h"
#include <TGeoMatrix.h>
#include "MathUtils/Utils.h"

using namespace o2::detectors;

ClassImp(o2::detectors::MatrixCache<o2::math_utils::Transform3D>);
ClassImp(o2::detectors::MatrixCache<o2::math_utils::Rotation2Df_t>);
ClassImp(o2::detectors::DetMatrixCache);

//_______________________________________________________
void DetMatrixCache::setSize(int s)
{
  // set the size of the matrix cache, can be done only once
  if (mSize != 0) {
    LOG(fatal) << "Cache size (N sensors) was already set to " << mSize;
  }
  mSize = s;
}

void DetMatrixCacheIndirect::setSize(int size, int sizeIndirect)
{
  // set the size of the matrix cache, can be done only once
  if (mSize != 0 || mIndirectSize != 0) {
    LOG(fatal) << "Cache size (N sensors) was already set to " << mSize << " / " << mIndirectSize;
  }
  if (mIndirectSize >= 32768) {
    LOG(fatal) << "Indirect cache size exceeds maximum size of 32768 (signed short)\n";
  }
  DetMatrixCache::setSize(size);
  mIndirection.resize(mIndirectSize = sizeIndirect, -1);
}
