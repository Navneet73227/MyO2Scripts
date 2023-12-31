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

/// \file Cluster.cxx
/// \brief Implementation of the ITSMFT cluster

#include "DataFormatsITSMFT/Cluster.h"
#include <fairlogger/Logger.h>

#include <TMath.h>
#include <TString.h>

#include <cstdlib>

using namespace o2::itsmft;

ClassImp(o2::itsmft::Cluster);

#ifdef _ClusterTopology_
  //______________________________________________________________________________
  void Cluster::resetPattern()
{
  // reset pixels pattern
  memset(mPattern, 0, kMaxPatternBytes * sizeof(UChar_t));
}

//______________________________________________________________________________
Bool_t Cluster::testPixel(UShort_t row, UShort_t col) const
{
  // test if pixel at relative row,col is fired
  int nbits = row * getPatternColSpan() + col;
  if (nbits >= kMaxPatternBits)
    return kFALSE;
  int bytn = nbits >> 3; // 1/8
  int bitn = 7 - (nbits % 8);
  return (mPattern[bytn] & (0x1 << bitn)) != 0;
  //
}

#endif
/*
//______________________________________________________________________________
Bool_t Cluster::hasCommonTrack(const Cluster* cl) const
{
  // check if clusters have common tracks
  for (int i = 0; i < maxLabels; i++) {
    Label lbi = getLabel(i);
    if ( lbi.isEmpty() ) break;
    if ( !lbi.isPosTrackID() ) continue;

    for (int j = 0; j < maxLabels; j++) {
      Label lbj = cl->getLabel(j);
      if ( lbj.isEmpty() ) break;
      if ( !lbj.isPosTrackID() ) continue;
      if (lbi == lbj) return kTRUE;
    }
  }
  return kFALSE;
}
*/
//______________________________________________________________________________
void Cluster::print() const
{
  // print itself
  printf("Sensor %5d, nRow:%3d nCol:%3d n:%d |Err^2:%.3e %.3e %+.3e |", getSensorID(), getNx(), getNz(), getNPix(),
         getSigmaY2(), getSigmaZ2(), getSigmaYZ());
  printf("XYZ: %+.4e %+.4e %+.4e\n", getX(), getY(), getZ());
//
#ifdef _ClusterTopology_
  int nr = getPatternRowSpan();
  int nc = getPatternColSpan();
  printf("Pattern: %d rows from %d", nr, mPatternRowMin);
  if (isPatternRowsTruncated())
    printf("(truncated)");
  printf(", %d cols from %d", nc, mPatternColMin);
  if (isPatternColsTruncated())
    printf("(truncated)");
  printf("\n");
  for (int ir = 0; ir < nr; ir++) {
    for (int ic = 0; ic < nc; ic++)
      printf("%c", testPixel(ir, ic) ? '+' : '-');
    printf("\n");
  }
#endif
}

#ifdef _ClusterTopology_
//______________________________________________________________________________
void Cluster::getDiffPattern(std::vector<std::pair<short, short>>& diffv, short colRef, short rowRef) const
{
  // fill vector with incremental differences starting from colRed / rowRef
  int nr = getPatternRowSpan();
  int nc = getPatternColSpan();
  diffv.clear();
  for (short ir = 0; ir < nr; ir++) {
    for (short ic0 = 0; ic0 < nc; ic0++) {
      short ic = (ir & 0x1) ? nc - ic0 - 1 : ic0; // left-to-right for even rows, right-to-left for odd columns
      if (testPixel(ir, ic)) {
        short row = ir + mPatternRowMin, col = ic + mPatternColMin;
        short drow = row - rowRef, dcol = col - colRef;
        if (!dcol && !drow) {
          continue;
        }
        diffv.emplace_back(dcol, drow);
        colRef = col;
        rowRef = row;
      }
    }
  }
  // flag end of the pattern
  diffv.emplace_back(0, 0);
}
#endif
