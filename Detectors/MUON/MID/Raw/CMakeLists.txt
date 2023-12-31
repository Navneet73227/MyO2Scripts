# Copyright 2019-2020 CERN and copyright holders of ALICE O2. See
# https://alice-o2.web.cern.ch/copyright for details of the copyright holders.
# All rights not expressly granted are reserved.
#
# This software is distributed under the terms of the GNU General Public License
# v3 (GPL Version 3), copied verbatim in the file "COPYING".
#
# In applying this license CERN does not waive the privileges and immunities
# granted to it by virtue of its status as an Intergovernmental Organization or
# submit itself to any jurisdiction.

o2_add_library(
  MIDRaw
  SOURCES src/ColumnDataToLocalBoard.cxx
          src/CrateMapper.cxx
          src/CrateMasks.cxx
          src/DecodedDataAggregator.cxx
          src/Decoder.cxx
          src/ElectronicsDelay.cxx
          src/ELinkDataShaper.cxx
          src/ELinkDecoder.cxx
          src/ELinkManager.cxx
          src/Encoder.cxx
          src/FEEIdConfig.cxx
          src/GBTUserLogicEncoder.cxx
          src/LinkDecoder.cxx
          src/RawFileReader.cxx
          src/ROBoardConfig.cxx
          src/ROBoardConfigHandler.cxx
          src/ROBoardResponse.cxx
  PUBLIC_LINK_LIBRARIES
    Microsoft.GSL::GSL
    O2::DataFormatsMID
    O2::Headers
    O2::DPLUtils
    O2::CommonConstants
    O2::DetectorsRaw
    O2::MIDBase
  TARGETVARNAME midrawtarget)
# target_compile_definitions(${midrawtarget} PRIVATE "MID_RAW_VECTORS")

add_subdirectory(exe)

if(BUILD_TESTING)
  add_subdirectory(test)
endif()
