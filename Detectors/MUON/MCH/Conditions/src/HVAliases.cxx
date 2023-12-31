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

#include "HVAliases.h"

namespace o2::mch::dcs
{
std::vector<std::string> expectedHVAliasesVoltages = {
  "MchHvLvLeft/Chamber00Left/Quad1Sect0.actual.vMon",
  "MchHvLvLeft/Chamber00Left/Quad1Sect1.actual.vMon",
  "MchHvLvLeft/Chamber00Left/Quad1Sect2.actual.vMon",
  "MchHvLvLeft/Chamber00Left/Quad2Sect0.actual.vMon",
  "MchHvLvLeft/Chamber00Left/Quad2Sect1.actual.vMon",
  "MchHvLvLeft/Chamber00Left/Quad2Sect2.actual.vMon",
  "MchHvLvLeft/Chamber01Left/Quad1Sect0.actual.vMon",
  "MchHvLvLeft/Chamber01Left/Quad1Sect1.actual.vMon",
  "MchHvLvLeft/Chamber01Left/Quad1Sect2.actual.vMon",
  "MchHvLvLeft/Chamber01Left/Quad2Sect0.actual.vMon",
  "MchHvLvLeft/Chamber01Left/Quad2Sect1.actual.vMon",
  "MchHvLvLeft/Chamber01Left/Quad2Sect2.actual.vMon",
  "MchHvLvLeft/Chamber02Left/Quad1Sect0.actual.vMon",
  "MchHvLvLeft/Chamber02Left/Quad1Sect1.actual.vMon",
  "MchHvLvLeft/Chamber02Left/Quad1Sect2.actual.vMon",
  "MchHvLvLeft/Chamber02Left/Quad2Sect0.actual.vMon",
  "MchHvLvLeft/Chamber02Left/Quad2Sect1.actual.vMon",
  "MchHvLvLeft/Chamber02Left/Quad2Sect2.actual.vMon",
  "MchHvLvLeft/Chamber03Left/Quad1Sect0.actual.vMon",
  "MchHvLvLeft/Chamber03Left/Quad1Sect1.actual.vMon",
  "MchHvLvLeft/Chamber03Left/Quad1Sect2.actual.vMon",
  "MchHvLvLeft/Chamber03Left/Quad2Sect0.actual.vMon",
  "MchHvLvLeft/Chamber03Left/Quad2Sect1.actual.vMon",
  "MchHvLvLeft/Chamber03Left/Quad2Sect2.actual.vMon",
  "MchHvLvLeft/Chamber04Left/Slat00.actual.vMon",
  "MchHvLvLeft/Chamber04Left/Slat01.actual.vMon",
  "MchHvLvLeft/Chamber04Left/Slat02.actual.vMon",
  "MchHvLvLeft/Chamber04Left/Slat03.actual.vMon",
  "MchHvLvLeft/Chamber04Left/Slat04.actual.vMon",
  "MchHvLvLeft/Chamber04Left/Slat05.actual.vMon",
  "MchHvLvLeft/Chamber04Left/Slat06.actual.vMon",
  "MchHvLvLeft/Chamber04Left/Slat07.actual.vMon",
  "MchHvLvLeft/Chamber04Left/Slat08.actual.vMon",
  "MchHvLvLeft/Chamber05Left/Slat00.actual.vMon",
  "MchHvLvLeft/Chamber05Left/Slat01.actual.vMon",
  "MchHvLvLeft/Chamber05Left/Slat02.actual.vMon",
  "MchHvLvLeft/Chamber05Left/Slat03.actual.vMon",
  "MchHvLvLeft/Chamber05Left/Slat04.actual.vMon",
  "MchHvLvLeft/Chamber05Left/Slat05.actual.vMon",
  "MchHvLvLeft/Chamber05Left/Slat06.actual.vMon",
  "MchHvLvLeft/Chamber05Left/Slat07.actual.vMon",
  "MchHvLvLeft/Chamber05Left/Slat08.actual.vMon",
  "MchHvLvLeft/Chamber06Left/Slat00.actual.vMon",
  "MchHvLvLeft/Chamber06Left/Slat01.actual.vMon",
  "MchHvLvLeft/Chamber06Left/Slat02.actual.vMon",
  "MchHvLvLeft/Chamber06Left/Slat03.actual.vMon",
  "MchHvLvLeft/Chamber06Left/Slat04.actual.vMon",
  "MchHvLvLeft/Chamber06Left/Slat05.actual.vMon",
  "MchHvLvLeft/Chamber06Left/Slat06.actual.vMon",
  "MchHvLvLeft/Chamber06Left/Slat07.actual.vMon",
  "MchHvLvLeft/Chamber06Left/Slat08.actual.vMon",
  "MchHvLvLeft/Chamber06Left/Slat09.actual.vMon",
  "MchHvLvLeft/Chamber06Left/Slat10.actual.vMon",
  "MchHvLvLeft/Chamber06Left/Slat11.actual.vMon",
  "MchHvLvLeft/Chamber06Left/Slat12.actual.vMon",
  "MchHvLvLeft/Chamber07Left/Slat00.actual.vMon",
  "MchHvLvLeft/Chamber07Left/Slat01.actual.vMon",
  "MchHvLvLeft/Chamber07Left/Slat02.actual.vMon",
  "MchHvLvLeft/Chamber07Left/Slat03.actual.vMon",
  "MchHvLvLeft/Chamber07Left/Slat04.actual.vMon",
  "MchHvLvLeft/Chamber07Left/Slat05.actual.vMon",
  "MchHvLvLeft/Chamber07Left/Slat06.actual.vMon",
  "MchHvLvLeft/Chamber07Left/Slat07.actual.vMon",
  "MchHvLvLeft/Chamber07Left/Slat08.actual.vMon",
  "MchHvLvLeft/Chamber07Left/Slat09.actual.vMon",
  "MchHvLvLeft/Chamber07Left/Slat10.actual.vMon",
  "MchHvLvLeft/Chamber07Left/Slat11.actual.vMon",
  "MchHvLvLeft/Chamber07Left/Slat12.actual.vMon",
  "MchHvLvLeft/Chamber08Left/Slat00.actual.vMon",
  "MchHvLvLeft/Chamber08Left/Slat01.actual.vMon",
  "MchHvLvLeft/Chamber08Left/Slat02.actual.vMon",
  "MchHvLvLeft/Chamber08Left/Slat03.actual.vMon",
  "MchHvLvLeft/Chamber08Left/Slat04.actual.vMon",
  "MchHvLvLeft/Chamber08Left/Slat05.actual.vMon",
  "MchHvLvLeft/Chamber08Left/Slat06.actual.vMon",
  "MchHvLvLeft/Chamber08Left/Slat07.actual.vMon",
  "MchHvLvLeft/Chamber08Left/Slat08.actual.vMon",
  "MchHvLvLeft/Chamber08Left/Slat09.actual.vMon",
  "MchHvLvLeft/Chamber08Left/Slat10.actual.vMon",
  "MchHvLvLeft/Chamber08Left/Slat11.actual.vMon",
  "MchHvLvLeft/Chamber08Left/Slat12.actual.vMon",
  "MchHvLvLeft/Chamber09Left/Slat00.actual.vMon",
  "MchHvLvLeft/Chamber09Left/Slat01.actual.vMon",
  "MchHvLvLeft/Chamber09Left/Slat02.actual.vMon",
  "MchHvLvLeft/Chamber09Left/Slat03.actual.vMon",
  "MchHvLvLeft/Chamber09Left/Slat04.actual.vMon",
  "MchHvLvLeft/Chamber09Left/Slat05.actual.vMon",
  "MchHvLvLeft/Chamber09Left/Slat06.actual.vMon",
  "MchHvLvLeft/Chamber09Left/Slat07.actual.vMon",
  "MchHvLvLeft/Chamber09Left/Slat08.actual.vMon",
  "MchHvLvLeft/Chamber09Left/Slat09.actual.vMon",
  "MchHvLvLeft/Chamber09Left/Slat10.actual.vMon",
  "MchHvLvLeft/Chamber09Left/Slat11.actual.vMon",
  "MchHvLvLeft/Chamber09Left/Slat12.actual.vMon",
  "MchHvLvRight/Chamber00Right/Quad0Sect0.actual.vMon",
  "MchHvLvRight/Chamber00Right/Quad0Sect1.actual.vMon",
  "MchHvLvRight/Chamber00Right/Quad0Sect2.actual.vMon",
  "MchHvLvRight/Chamber00Right/Quad3Sect0.actual.vMon",
  "MchHvLvRight/Chamber00Right/Quad3Sect1.actual.vMon",
  "MchHvLvRight/Chamber00Right/Quad3Sect2.actual.vMon",
  "MchHvLvRight/Chamber01Right/Quad0Sect0.actual.vMon",
  "MchHvLvRight/Chamber01Right/Quad0Sect1.actual.vMon",
  "MchHvLvRight/Chamber01Right/Quad0Sect2.actual.vMon",
  "MchHvLvRight/Chamber01Right/Quad3Sect0.actual.vMon",
  "MchHvLvRight/Chamber01Right/Quad3Sect1.actual.vMon",
  "MchHvLvRight/Chamber01Right/Quad3Sect2.actual.vMon",
  "MchHvLvRight/Chamber02Right/Quad0Sect0.actual.vMon",
  "MchHvLvRight/Chamber02Right/Quad0Sect1.actual.vMon",
  "MchHvLvRight/Chamber02Right/Quad0Sect2.actual.vMon",
  "MchHvLvRight/Chamber02Right/Quad3Sect0.actual.vMon",
  "MchHvLvRight/Chamber02Right/Quad3Sect1.actual.vMon",
  "MchHvLvRight/Chamber02Right/Quad3Sect2.actual.vMon",
  "MchHvLvRight/Chamber03Right/Quad0Sect0.actual.vMon",
  "MchHvLvRight/Chamber03Right/Quad0Sect1.actual.vMon",
  "MchHvLvRight/Chamber03Right/Quad0Sect2.actual.vMon",
  "MchHvLvRight/Chamber03Right/Quad3Sect0.actual.vMon",
  "MchHvLvRight/Chamber03Right/Quad3Sect1.actual.vMon",
  "MchHvLvRight/Chamber03Right/Quad3Sect2.actual.vMon",
  "MchHvLvRight/Chamber04Right/Slat00.actual.vMon",
  "MchHvLvRight/Chamber04Right/Slat01.actual.vMon",
  "MchHvLvRight/Chamber04Right/Slat02.actual.vMon",
  "MchHvLvRight/Chamber04Right/Slat03.actual.vMon",
  "MchHvLvRight/Chamber04Right/Slat04.actual.vMon",
  "MchHvLvRight/Chamber04Right/Slat05.actual.vMon",
  "MchHvLvRight/Chamber04Right/Slat06.actual.vMon",
  "MchHvLvRight/Chamber04Right/Slat07.actual.vMon",
  "MchHvLvRight/Chamber04Right/Slat08.actual.vMon",
  "MchHvLvRight/Chamber05Right/Slat00.actual.vMon",
  "MchHvLvRight/Chamber05Right/Slat01.actual.vMon",
  "MchHvLvRight/Chamber05Right/Slat02.actual.vMon",
  "MchHvLvRight/Chamber05Right/Slat03.actual.vMon",
  "MchHvLvRight/Chamber05Right/Slat04.actual.vMon",
  "MchHvLvRight/Chamber05Right/Slat05.actual.vMon",
  "MchHvLvRight/Chamber05Right/Slat06.actual.vMon",
  "MchHvLvRight/Chamber05Right/Slat07.actual.vMon",
  "MchHvLvRight/Chamber05Right/Slat08.actual.vMon",
  "MchHvLvRight/Chamber06Right/Slat00.actual.vMon",
  "MchHvLvRight/Chamber06Right/Slat01.actual.vMon",
  "MchHvLvRight/Chamber06Right/Slat02.actual.vMon",
  "MchHvLvRight/Chamber06Right/Slat03.actual.vMon",
  "MchHvLvRight/Chamber06Right/Slat04.actual.vMon",
  "MchHvLvRight/Chamber06Right/Slat05.actual.vMon",
  "MchHvLvRight/Chamber06Right/Slat06.actual.vMon",
  "MchHvLvRight/Chamber06Right/Slat07.actual.vMon",
  "MchHvLvRight/Chamber06Right/Slat08.actual.vMon",
  "MchHvLvRight/Chamber06Right/Slat09.actual.vMon",
  "MchHvLvRight/Chamber06Right/Slat10.actual.vMon",
  "MchHvLvRight/Chamber06Right/Slat11.actual.vMon",
  "MchHvLvRight/Chamber06Right/Slat12.actual.vMon",
  "MchHvLvRight/Chamber07Right/Slat00.actual.vMon",
  "MchHvLvRight/Chamber07Right/Slat01.actual.vMon",
  "MchHvLvRight/Chamber07Right/Slat02.actual.vMon",
  "MchHvLvRight/Chamber07Right/Slat03.actual.vMon",
  "MchHvLvRight/Chamber07Right/Slat04.actual.vMon",
  "MchHvLvRight/Chamber07Right/Slat05.actual.vMon",
  "MchHvLvRight/Chamber07Right/Slat06.actual.vMon",
  "MchHvLvRight/Chamber07Right/Slat07.actual.vMon",
  "MchHvLvRight/Chamber07Right/Slat08.actual.vMon",
  "MchHvLvRight/Chamber07Right/Slat09.actual.vMon",
  "MchHvLvRight/Chamber07Right/Slat10.actual.vMon",
  "MchHvLvRight/Chamber07Right/Slat11.actual.vMon",
  "MchHvLvRight/Chamber07Right/Slat12.actual.vMon",
  "MchHvLvRight/Chamber08Right/Slat00.actual.vMon",
  "MchHvLvRight/Chamber08Right/Slat01.actual.vMon",
  "MchHvLvRight/Chamber08Right/Slat02.actual.vMon",
  "MchHvLvRight/Chamber08Right/Slat03.actual.vMon",
  "MchHvLvRight/Chamber08Right/Slat04.actual.vMon",
  "MchHvLvRight/Chamber08Right/Slat05.actual.vMon",
  "MchHvLvRight/Chamber08Right/Slat06.actual.vMon",
  "MchHvLvRight/Chamber08Right/Slat07.actual.vMon",
  "MchHvLvRight/Chamber08Right/Slat08.actual.vMon",
  "MchHvLvRight/Chamber08Right/Slat09.actual.vMon",
  "MchHvLvRight/Chamber08Right/Slat10.actual.vMon",
  "MchHvLvRight/Chamber08Right/Slat11.actual.vMon",
  "MchHvLvRight/Chamber08Right/Slat12.actual.vMon",
  "MchHvLvRight/Chamber09Right/Slat00.actual.vMon",
  "MchHvLvRight/Chamber09Right/Slat01.actual.vMon",
  "MchHvLvRight/Chamber09Right/Slat02.actual.vMon",
  "MchHvLvRight/Chamber09Right/Slat03.actual.vMon",
  "MchHvLvRight/Chamber09Right/Slat04.actual.vMon",
  "MchHvLvRight/Chamber09Right/Slat05.actual.vMon",
  "MchHvLvRight/Chamber09Right/Slat06.actual.vMon",
  "MchHvLvRight/Chamber09Right/Slat07.actual.vMon",
  "MchHvLvRight/Chamber09Right/Slat08.actual.vMon",
  "MchHvLvRight/Chamber09Right/Slat09.actual.vMon",
  "MchHvLvRight/Chamber09Right/Slat10.actual.vMon",
  "MchHvLvRight/Chamber09Right/Slat11.actual.vMon",
  "MchHvLvRight/Chamber09Right/Slat12.actual.vMon"};

std::vector<std::string> expectedHVAliasesCurrents = {
  "MchHvLvLeft/Chamber00Left/Quad1Sect0.actual.iMon",
  "MchHvLvLeft/Chamber00Left/Quad1Sect1.actual.iMon",
  "MchHvLvLeft/Chamber00Left/Quad1Sect2.actual.iMon",
  "MchHvLvLeft/Chamber00Left/Quad2Sect0.actual.iMon",
  "MchHvLvLeft/Chamber00Left/Quad2Sect1.actual.iMon",
  "MchHvLvLeft/Chamber00Left/Quad2Sect2.actual.iMon",
  "MchHvLvLeft/Chamber01Left/Quad1Sect0.actual.iMon",
  "MchHvLvLeft/Chamber01Left/Quad1Sect1.actual.iMon",
  "MchHvLvLeft/Chamber01Left/Quad1Sect2.actual.iMon",
  "MchHvLvLeft/Chamber01Left/Quad2Sect0.actual.iMon",
  "MchHvLvLeft/Chamber01Left/Quad2Sect1.actual.iMon",
  "MchHvLvLeft/Chamber01Left/Quad2Sect2.actual.iMon",
  "MchHvLvLeft/Chamber02Left/Quad1Sect0.actual.iMon",
  "MchHvLvLeft/Chamber02Left/Quad1Sect1.actual.iMon",
  "MchHvLvLeft/Chamber02Left/Quad1Sect2.actual.iMon",
  "MchHvLvLeft/Chamber02Left/Quad2Sect0.actual.iMon",
  "MchHvLvLeft/Chamber02Left/Quad2Sect1.actual.iMon",
  "MchHvLvLeft/Chamber02Left/Quad2Sect2.actual.iMon",
  "MchHvLvLeft/Chamber03Left/Quad1Sect0.actual.iMon",
  "MchHvLvLeft/Chamber03Left/Quad1Sect1.actual.iMon",
  "MchHvLvLeft/Chamber03Left/Quad1Sect2.actual.iMon",
  "MchHvLvLeft/Chamber03Left/Quad2Sect0.actual.iMon",
  "MchHvLvLeft/Chamber03Left/Quad2Sect1.actual.iMon",
  "MchHvLvLeft/Chamber03Left/Quad2Sect2.actual.iMon",
  "MchHvLvLeft/Chamber04Left/Slat00.actual.iMon",
  "MchHvLvLeft/Chamber04Left/Slat01.actual.iMon",
  "MchHvLvLeft/Chamber04Left/Slat02.actual.iMon",
  "MchHvLvLeft/Chamber04Left/Slat03.actual.iMon",
  "MchHvLvLeft/Chamber04Left/Slat04.actual.iMon",
  "MchHvLvLeft/Chamber04Left/Slat05.actual.iMon",
  "MchHvLvLeft/Chamber04Left/Slat06.actual.iMon",
  "MchHvLvLeft/Chamber04Left/Slat07.actual.iMon",
  "MchHvLvLeft/Chamber04Left/Slat08.actual.iMon",
  "MchHvLvLeft/Chamber05Left/Slat00.actual.iMon",
  "MchHvLvLeft/Chamber05Left/Slat01.actual.iMon",
  "MchHvLvLeft/Chamber05Left/Slat02.actual.iMon",
  "MchHvLvLeft/Chamber05Left/Slat03.actual.iMon",
  "MchHvLvLeft/Chamber05Left/Slat04.actual.iMon",
  "MchHvLvLeft/Chamber05Left/Slat05.actual.iMon",
  "MchHvLvLeft/Chamber05Left/Slat06.actual.iMon",
  "MchHvLvLeft/Chamber05Left/Slat07.actual.iMon",
  "MchHvLvLeft/Chamber05Left/Slat08.actual.iMon",
  "MchHvLvLeft/Chamber06Left/Slat00.actual.iMon",
  "MchHvLvLeft/Chamber06Left/Slat01.actual.iMon",
  "MchHvLvLeft/Chamber06Left/Slat02.actual.iMon",
  "MchHvLvLeft/Chamber06Left/Slat03.actual.iMon",
  "MchHvLvLeft/Chamber06Left/Slat04.actual.iMon",
  "MchHvLvLeft/Chamber06Left/Slat05.actual.iMon",
  "MchHvLvLeft/Chamber06Left/Slat06.actual.iMon",
  "MchHvLvLeft/Chamber06Left/Slat07.actual.iMon",
  "MchHvLvLeft/Chamber06Left/Slat08.actual.iMon",
  "MchHvLvLeft/Chamber06Left/Slat09.actual.iMon",
  "MchHvLvLeft/Chamber06Left/Slat10.actual.iMon",
  "MchHvLvLeft/Chamber06Left/Slat11.actual.iMon",
  "MchHvLvLeft/Chamber06Left/Slat12.actual.iMon",
  "MchHvLvLeft/Chamber07Left/Slat00.actual.iMon",
  "MchHvLvLeft/Chamber07Left/Slat01.actual.iMon",
  "MchHvLvLeft/Chamber07Left/Slat02.actual.iMon",
  "MchHvLvLeft/Chamber07Left/Slat03.actual.iMon",
  "MchHvLvLeft/Chamber07Left/Slat04.actual.iMon",
  "MchHvLvLeft/Chamber07Left/Slat05.actual.iMon",
  "MchHvLvLeft/Chamber07Left/Slat06.actual.iMon",
  "MchHvLvLeft/Chamber07Left/Slat07.actual.iMon",
  "MchHvLvLeft/Chamber07Left/Slat08.actual.iMon",
  "MchHvLvLeft/Chamber07Left/Slat09.actual.iMon",
  "MchHvLvLeft/Chamber07Left/Slat10.actual.iMon",
  "MchHvLvLeft/Chamber07Left/Slat11.actual.iMon",
  "MchHvLvLeft/Chamber07Left/Slat12.actual.iMon",
  "MchHvLvLeft/Chamber08Left/Slat00.actual.iMon",
  "MchHvLvLeft/Chamber08Left/Slat01.actual.iMon",
  "MchHvLvLeft/Chamber08Left/Slat02.actual.iMon",
  "MchHvLvLeft/Chamber08Left/Slat03.actual.iMon",
  "MchHvLvLeft/Chamber08Left/Slat04.actual.iMon",
  "MchHvLvLeft/Chamber08Left/Slat05.actual.iMon",
  "MchHvLvLeft/Chamber08Left/Slat06.actual.iMon",
  "MchHvLvLeft/Chamber08Left/Slat07.actual.iMon",
  "MchHvLvLeft/Chamber08Left/Slat08.actual.iMon",
  "MchHvLvLeft/Chamber08Left/Slat09.actual.iMon",
  "MchHvLvLeft/Chamber08Left/Slat10.actual.iMon",
  "MchHvLvLeft/Chamber08Left/Slat11.actual.iMon",
  "MchHvLvLeft/Chamber08Left/Slat12.actual.iMon",
  "MchHvLvLeft/Chamber09Left/Slat00.actual.iMon",
  "MchHvLvLeft/Chamber09Left/Slat01.actual.iMon",
  "MchHvLvLeft/Chamber09Left/Slat02.actual.iMon",
  "MchHvLvLeft/Chamber09Left/Slat03.actual.iMon",
  "MchHvLvLeft/Chamber09Left/Slat04.actual.iMon",
  "MchHvLvLeft/Chamber09Left/Slat05.actual.iMon",
  "MchHvLvLeft/Chamber09Left/Slat06.actual.iMon",
  "MchHvLvLeft/Chamber09Left/Slat07.actual.iMon",
  "MchHvLvLeft/Chamber09Left/Slat08.actual.iMon",
  "MchHvLvLeft/Chamber09Left/Slat09.actual.iMon",
  "MchHvLvLeft/Chamber09Left/Slat10.actual.iMon",
  "MchHvLvLeft/Chamber09Left/Slat11.actual.iMon",
  "MchHvLvLeft/Chamber09Left/Slat12.actual.iMon",
  "MchHvLvRight/Chamber00Right/Quad0Sect0.actual.iMon",
  "MchHvLvRight/Chamber00Right/Quad0Sect1.actual.iMon",
  "MchHvLvRight/Chamber00Right/Quad0Sect2.actual.iMon",
  "MchHvLvRight/Chamber00Right/Quad3Sect0.actual.iMon",
  "MchHvLvRight/Chamber00Right/Quad3Sect1.actual.iMon",
  "MchHvLvRight/Chamber00Right/Quad3Sect2.actual.iMon",
  "MchHvLvRight/Chamber01Right/Quad0Sect0.actual.iMon",
  "MchHvLvRight/Chamber01Right/Quad0Sect1.actual.iMon",
  "MchHvLvRight/Chamber01Right/Quad0Sect2.actual.iMon",
  "MchHvLvRight/Chamber01Right/Quad3Sect0.actual.iMon",
  "MchHvLvRight/Chamber01Right/Quad3Sect1.actual.iMon",
  "MchHvLvRight/Chamber01Right/Quad3Sect2.actual.iMon",
  "MchHvLvRight/Chamber02Right/Quad0Sect0.actual.iMon",
  "MchHvLvRight/Chamber02Right/Quad0Sect1.actual.iMon",
  "MchHvLvRight/Chamber02Right/Quad0Sect2.actual.iMon",
  "MchHvLvRight/Chamber02Right/Quad3Sect0.actual.iMon",
  "MchHvLvRight/Chamber02Right/Quad3Sect1.actual.iMon",
  "MchHvLvRight/Chamber02Right/Quad3Sect2.actual.iMon",
  "MchHvLvRight/Chamber03Right/Quad0Sect0.actual.iMon",
  "MchHvLvRight/Chamber03Right/Quad0Sect1.actual.iMon",
  "MchHvLvRight/Chamber03Right/Quad0Sect2.actual.iMon",
  "MchHvLvRight/Chamber03Right/Quad3Sect0.actual.iMon",
  "MchHvLvRight/Chamber03Right/Quad3Sect1.actual.iMon",
  "MchHvLvRight/Chamber03Right/Quad3Sect2.actual.iMon",
  "MchHvLvRight/Chamber04Right/Slat00.actual.iMon",
  "MchHvLvRight/Chamber04Right/Slat01.actual.iMon",
  "MchHvLvRight/Chamber04Right/Slat02.actual.iMon",
  "MchHvLvRight/Chamber04Right/Slat03.actual.iMon",
  "MchHvLvRight/Chamber04Right/Slat04.actual.iMon",
  "MchHvLvRight/Chamber04Right/Slat05.actual.iMon",
  "MchHvLvRight/Chamber04Right/Slat06.actual.iMon",
  "MchHvLvRight/Chamber04Right/Slat07.actual.iMon",
  "MchHvLvRight/Chamber04Right/Slat08.actual.iMon",
  "MchHvLvRight/Chamber05Right/Slat00.actual.iMon",
  "MchHvLvRight/Chamber05Right/Slat01.actual.iMon",
  "MchHvLvRight/Chamber05Right/Slat02.actual.iMon",
  "MchHvLvRight/Chamber05Right/Slat03.actual.iMon",
  "MchHvLvRight/Chamber05Right/Slat04.actual.iMon",
  "MchHvLvRight/Chamber05Right/Slat05.actual.iMon",
  "MchHvLvRight/Chamber05Right/Slat06.actual.iMon",
  "MchHvLvRight/Chamber05Right/Slat07.actual.iMon",
  "MchHvLvRight/Chamber05Right/Slat08.actual.iMon",
  "MchHvLvRight/Chamber06Right/Slat00.actual.iMon",
  "MchHvLvRight/Chamber06Right/Slat01.actual.iMon",
  "MchHvLvRight/Chamber06Right/Slat02.actual.iMon",
  "MchHvLvRight/Chamber06Right/Slat03.actual.iMon",
  "MchHvLvRight/Chamber06Right/Slat04.actual.iMon",
  "MchHvLvRight/Chamber06Right/Slat05.actual.iMon",
  "MchHvLvRight/Chamber06Right/Slat06.actual.iMon",
  "MchHvLvRight/Chamber06Right/Slat07.actual.iMon",
  "MchHvLvRight/Chamber06Right/Slat08.actual.iMon",
  "MchHvLvRight/Chamber06Right/Slat09.actual.iMon",
  "MchHvLvRight/Chamber06Right/Slat10.actual.iMon",
  "MchHvLvRight/Chamber06Right/Slat11.actual.iMon",
  "MchHvLvRight/Chamber06Right/Slat12.actual.iMon",
  "MchHvLvRight/Chamber07Right/Slat00.actual.iMon",
  "MchHvLvRight/Chamber07Right/Slat01.actual.iMon",
  "MchHvLvRight/Chamber07Right/Slat02.actual.iMon",
  "MchHvLvRight/Chamber07Right/Slat03.actual.iMon",
  "MchHvLvRight/Chamber07Right/Slat04.actual.iMon",
  "MchHvLvRight/Chamber07Right/Slat05.actual.iMon",
  "MchHvLvRight/Chamber07Right/Slat06.actual.iMon",
  "MchHvLvRight/Chamber07Right/Slat07.actual.iMon",
  "MchHvLvRight/Chamber07Right/Slat08.actual.iMon",
  "MchHvLvRight/Chamber07Right/Slat09.actual.iMon",
  "MchHvLvRight/Chamber07Right/Slat10.actual.iMon",
  "MchHvLvRight/Chamber07Right/Slat11.actual.iMon",
  "MchHvLvRight/Chamber07Right/Slat12.actual.iMon",
  "MchHvLvRight/Chamber08Right/Slat00.actual.iMon",
  "MchHvLvRight/Chamber08Right/Slat01.actual.iMon",
  "MchHvLvRight/Chamber08Right/Slat02.actual.iMon",
  "MchHvLvRight/Chamber08Right/Slat03.actual.iMon",
  "MchHvLvRight/Chamber08Right/Slat04.actual.iMon",
  "MchHvLvRight/Chamber08Right/Slat05.actual.iMon",
  "MchHvLvRight/Chamber08Right/Slat06.actual.iMon",
  "MchHvLvRight/Chamber08Right/Slat07.actual.iMon",
  "MchHvLvRight/Chamber08Right/Slat08.actual.iMon",
  "MchHvLvRight/Chamber08Right/Slat09.actual.iMon",
  "MchHvLvRight/Chamber08Right/Slat10.actual.iMon",
  "MchHvLvRight/Chamber08Right/Slat11.actual.iMon",
  "MchHvLvRight/Chamber08Right/Slat12.actual.iMon",
  "MchHvLvRight/Chamber09Right/Slat00.actual.iMon",
  "MchHvLvRight/Chamber09Right/Slat01.actual.iMon",
  "MchHvLvRight/Chamber09Right/Slat02.actual.iMon",
  "MchHvLvRight/Chamber09Right/Slat03.actual.iMon",
  "MchHvLvRight/Chamber09Right/Slat04.actual.iMon",
  "MchHvLvRight/Chamber09Right/Slat05.actual.iMon",
  "MchHvLvRight/Chamber09Right/Slat06.actual.iMon",
  "MchHvLvRight/Chamber09Right/Slat07.actual.iMon",
  "MchHvLvRight/Chamber09Right/Slat08.actual.iMon",
  "MchHvLvRight/Chamber09Right/Slat09.actual.iMon",
  "MchHvLvRight/Chamber09Right/Slat10.actual.iMon",
  "MchHvLvRight/Chamber09Right/Slat11.actual.iMon",
  "MchHvLvRight/Chamber09Right/Slat12.actual.iMon"};
} // namespace o2::mch::dcs
