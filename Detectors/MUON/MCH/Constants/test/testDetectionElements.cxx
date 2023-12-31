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

#define BOOST_TEST_MODULE Test MCHConstants DetectionElements
#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>

#include "MCHConstants/DetectionElements.h"

#include <array>
#include <boost/mpl/list.hpp>
#include <set>
#include <unordered_map>

BOOST_AUTO_TEST_CASE(CheckDeId2DeId)
{
  std::unordered_map<int, int> checkMap = {
    {100, 0},
    {101, 1},
    {102, 2},
    {103, 3},
    {200, 4},
    {201, 5},
    {202, 6},
    {203, 7},
    {300, 8},
    {301, 9},
    {302, 10},
    {303, 11},
    {400, 12},
    {401, 13},
    {402, 14},
    {403, 15},
    {500, 16},
    {501, 17},
    {502, 18},
    {503, 19},
    {504, 20},
    {505, 21},
    {506, 22},
    {507, 23},
    {508, 24},
    {509, 25},
    {510, 26},
    {511, 27},
    {512, 28},
    {513, 29},
    {514, 30},
    {515, 31},
    {516, 32},
    {517, 33},
    {600, 34},
    {601, 35},
    {602, 36},
    {603, 37},
    {604, 38},
    {605, 39},
    {606, 40},
    {607, 41},
    {608, 42},
    {609, 43},
    {610, 44},
    {611, 45},
    {612, 46},
    {613, 47},
    {614, 48},
    {615, 49},
    {616, 50},
    {617, 51},
    {700, 52},
    {701, 53},
    {702, 54},
    {703, 55},
    {704, 56},
    {705, 57},
    {706, 58},
    {707, 59},
    {708, 60},
    {709, 61},
    {710, 62},
    {711, 63},
    {712, 64},
    {713, 65},
    {714, 66},
    {715, 67},
    {716, 68},
    {717, 69},
    {718, 70},
    {719, 71},
    {720, 72},
    {721, 73},
    {722, 74},
    {723, 75},
    {724, 76},
    {725, 77},
    {800, 78},
    {801, 79},
    {802, 80},
    {803, 81},
    {804, 82},
    {805, 83},
    {806, 84},
    {807, 85},
    {808, 86},
    {809, 87},
    {810, 88},
    {811, 89},
    {812, 90},
    {813, 91},
    {814, 92},
    {815, 93},
    {816, 94},
    {817, 95},
    {818, 96},
    {819, 97},
    {820, 98},
    {821, 99},
    {822, 100},
    {823, 101},
    {824, 102},
    {825, 103},
    {900, 104},
    {901, 105},
    {902, 106},
    {903, 107},
    {904, 108},
    {905, 109},
    {906, 110},
    {907, 111},
    {908, 112},
    {909, 113},
    {910, 114},
    {911, 115},
    {912, 116},
    {913, 117},
    {914, 118},
    {915, 119},
    {916, 120},
    {917, 121},
    {918, 122},
    {919, 123},
    {920, 124},
    {921, 125},
    {922, 126},
    {923, 127},
    {924, 128},
    {925, 129},
    {1000, 130},
    {1001, 131},
    {1002, 132},
    {1003, 133},
    {1004, 134},
    {1005, 135},
    {1006, 136},
    {1007, 137},
    {1008, 138},
    {1009, 139},
    {1010, 140},
    {1011, 141},
    {1012, 142},
    {1013, 143},
    {1014, 144},
    {1015, 145},
    {1016, 146},
    {1017, 147},
    {1018, 148},
    {1019, 149},
    {1020, 150},
    {1021, 151},
    {1022, 152},
    {1023, 153},
    {1024, 154},
    {1025, 155}};

  for (auto deId : o2::mch::constants::deIdsForAllMCH) {
    auto expected = checkMap.find(deId);
    BOOST_CHECK_EQUAL(o2::mch::constants::deId2DeIndex(deId).value(), expected->second);
  }

  // non existing deId should return std::nullopt
  BOOST_CHECK(o2::mch::constants::deId2DeIndex(42) == std::nullopt);
}
