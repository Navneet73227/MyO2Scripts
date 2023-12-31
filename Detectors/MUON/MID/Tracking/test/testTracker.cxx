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

/// \file   MID/Tracking/test/testTracker.cxx
/// \brief  Test tracking device for MID
/// \author Diego Stocco <Diego.Stocco at cern.ch>
/// \date   15 March 2018

#define BOOST_TEST_MODULE midTracking
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include <boost/test/data/monomorphic/generators/xrange.hpp>
#include <boost/test/data/test_case.hpp>
#include <cstdint>
#include <string>
#include <sstream>
#include <vector>
#include "DataFormatsMID/Cluster.h"
#include "DataFormatsMID/Track.h"
#include "MIDBase/HitFinder.h"
#include "MIDBase/Mapping.h"
#include "MIDBase/MpArea.h"
#include "MIDTestingSimTools/TrackGenerator.h"
#include "MIDTracking/Tracker.h"
#include "MIDTracking/HitMapBuilder.h"

namespace o2
{
namespace mid
{

struct TrackClusters {
  Track track;
  std::vector<Cluster> clusters;
  int nFiredChambers;
  bool isReconstructible() { return nFiredChambers > 2; }
};

struct Helper {
  Mapping mapping;
  GeometryTransformer geoTrans;
  HitFinder hitFinder;
  TrackGenerator trackGen;
  Tracker tracker;
  Tracker trackerAll;
  HitMapBuilder hitMapBuilder;

  Helper() : mapping(), geoTrans(createDefaultTransformer()), hitFinder(geoTrans), trackGen(), tracker(geoTrans), trackerAll(geoTrans), hitMapBuilder(geoTrans)
  {
    tracker.init();
    trackerAll.init(true);
  }
};

static Helper helper;

TrackClusters getTrackClusters(const Track& track)
{
  TrackClusters trCl;
  trCl.track = track;
  trCl.nFiredChambers = 0;
  Mapping::MpStripIndex stripIndex;
  MpArea area;
  Cluster cl;
  for (int ich = 0; ich < 4; ++ich) {
    auto hits = helper.hitFinder.getLocalPositions(track, ich);
    bool isFired = false;
    for (auto& hit : hits) {
      int deId = hit.deId;
      float xPos = hit.xCoor;
      float yPos = hit.yCoor;
      stripIndex = helper.mapping.stripByPosition(xPos, yPos, 0, deId, false);
      if (!stripIndex.isValid()) {
        continue;
      }
      cl.deId = deId;
      cl.zCoor = 0.;
      area = helper.mapping.stripByLocation(stripIndex.strip, 0, stripIndex.line, stripIndex.column, deId);
      cl.yCoor = area.getCenterY();
      cl.yErr = area.getHalfSizeY() / std::sqrt(3.);
      stripIndex = helper.mapping.stripByPosition(xPos, yPos, 1, deId, false);
      area = helper.mapping.stripByLocation(stripIndex.strip, 1, stripIndex.line, stripIndex.column, deId);
      cl.xCoor = area.getCenterX();
      cl.xErr = area.getHalfSizeX() / std::sqrt(3.);
      cl.setBothFired();
      trCl.clusters.push_back(cl);
      isFired = true;
    } // loop on fired pos
    if (isFired) {
      ++(trCl.nFiredChambers);
    }
  }
  return trCl;
}

std::vector<TrackClusters> getTrackClusters(int nTracks)
{
  std::vector<TrackClusters> trackClusters;
  std::vector<Track> tracks = helper.trackGen.generate(nTracks);
  for (auto& track : tracks) {
    trackClusters.push_back(getTrackClusters(track));
  }
  return trackClusters;
}

std::string getTrackInfo(const Track& track)
{
  std::stringstream ss;
  ss << track << "  clusters: ";
  for (int ich = 0; ich < 4; ++ich) {
    ss << " " << track.getClusterMatched(ich);
  }
  return ss.str();
}

BOOST_DATA_TEST_CASE(TestMultipleTracks, boost::unit_test::data::xrange(1, 9), nTracksPerEvent)
{
  float chi2Cut = helper.tracker.getSigmaCut() * helper.tracker.getSigmaCut();
  int nTotFakes = 0, nTotReconstructible = 0;
  for (int ievt = 0; ievt < 1000; ++ievt) {
    std::vector<TrackClusters> trackClusters = getTrackClusters(nTracksPerEvent);
    std::vector<Cluster> clusters;

    // Fill string for debugging
    std::stringstream ss;
    ss << "\n";
    int itr = -1;
    for (auto& trCl : trackClusters) {
      ++itr;
      ss << "Track " << itr << ": " << trCl.track << "\n";
      for (auto& cl : trCl.clusters) {
        clusters.push_back(cl);
        ss << "  deId " << (int)cl.deId << " pos: (" << cl.xCoor << ", " << cl.yCoor << ")";
      }
      ss << "\n";
    }

    // Run tracker algorithm
    helper.tracker.process(clusters);

    // Further strings for debugging
    ss << "  Reconstructed tracks:\n";
    for (size_t ireco = 0; ireco < helper.tracker.getTracks().size(); ++ireco) {
      ss << "  " << helper.tracker.getTracks()[ireco] << "\n";
    }

    // Check that all reconstructible tracks are reconstructed
    size_t nReconstructible = 0;
    itr = -1;
    for (auto& trCl : trackClusters) {
      ++itr;
      bool isReco = false;
      for (size_t ireco = 0; ireco < helper.tracker.getTracks().size(); ++ireco) {
        if (helper.tracker.getTracks()[ireco].isCompatible(trCl.track, chi2Cut)) {
          isReco = true;
          break;
        }
      }
      bool isReconstructible = trCl.isReconstructible();
      // If the number of tracks is small, we can check that:
      // 1) all reconstructible tracks are reconstructed
      // 2) all non-reconstructible tracks are not
      // Case 2), however, is not always valid when we have many tracks,
      // since we can combine clusters from different tracks to build fakes
      bool testTrack = (isReconstructible || nTracksPerEvent < 4);
      if (testTrack) {
        BOOST_TEST(isReco == isReconstructible, ss.str() << "  track " << itr << " reco " << isReco
                                                         << " != reconstructible " << isReconstructible);
      }
      if (isReconstructible) {
        ++nReconstructible;
      }
    } // loop on input tracks
    nTotReconstructible += nReconstructible;
    int nFakes = helper.tracker.getTracks().size() - nReconstructible;
    if (nFakes > 0) {
      ++nTotFakes;
    }
  } // loop on events
  // To show the following message, run the test with: --log_level=message
  BOOST_TEST_MESSAGE("Fraction of fake tracks: " << (double)nTotFakes / (double)nTotReconstructible);
}

BOOST_DATA_TEST_CASE(TestAlgorithms, boost::unit_test::data::xrange(2, 3), nTracksPerEvent)
{
  float chi2Cut = helper.tracker.getSigmaCut() * helper.tracker.getSigmaCut();
  int nTotFakes = 0, nTotReconstructible = 0;
  for (int ievt = 0; ievt < 1000; ++ievt) {
    std::vector<TrackClusters> trackClusters = getTrackClusters(nTracksPerEvent);
    std::vector<Cluster> clusters;
    for (auto& trCl : trackClusters) {
      for (auto& cl : trCl.clusters) {
        clusters.push_back(cl);
      }
    }

    // Run tracker algorithm
    helper.tracker.process(clusters);
    helper.trackerAll.process(clusters);

    BOOST_TEST(helper.tracker.getTracks().size() <= helper.trackerAll.getTracks().size());

    for (auto& track : helper.tracker.getTracks()) {
      bool isCompatible = false;
      std::stringstream ss;
      ss << "\n"
         << getTrackInfo(track) << "  has no match in:\n";
      for (auto& trackAll : helper.trackerAll.getTracks()) {
        ss << getTrackInfo(trackAll) << "\n";
        if (trackAll.isCompatible(track, chi2Cut)) {
          isCompatible = true;
          break;
        }
      }
      BOOST_TEST(isCompatible, ss.str());
    }
  }
}

BOOST_AUTO_TEST_CASE(TestHitMapBuilder)
{
  for (int ievt = 0; ievt < 100; ++ievt) {
    std::vector<TrackClusters> trackClusters = getTrackClusters(1);
    for (auto& trCl : trackClusters) {
      // Run tracker algorithm
      helper.tracker.process(trCl.clusters);
      std::vector<Track> tracks = helper.tracker.getTracks();
      for (auto& track : tracks) {
        helper.hitMapBuilder.buildTrackInfo(track, trCl.clusters);
        BOOST_TEST(track.getEfficiencyFlag() >= 1);
      }
    }
  }
}
} // namespace mid
} // namespace o2
