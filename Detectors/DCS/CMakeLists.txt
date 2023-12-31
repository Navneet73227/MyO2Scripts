# Copyright 2019-2020 CERN and copyright holders of ALICE O2.
# See https://alice-o2.web.cern.ch/copyright for details of the copyright holders.
# All rights not expressly granted are reserved.
#
# This software is distributed under the terms of the GNU General Public
# License v3 (GPL Version 3), copied verbatim in the file "COPYING".
#
# In applying this license CERN does not waive the privileges and immunities
# granted to it by virtue of its status as an Intergovernmental Organization
# or submit itself to any jurisdiction.

o2_add_library(
  DetectorsDCS
  TARGETVARNAME targetName
  SOURCES src/AliasExpander.cxx
          src/DataPointCompositeObject.cxx
          src/DataPointCreator.cxx
          src/DataPointGenerator.cxx
          src/DataPointIdentifier.cxx
          src/DataPointValue.cxx
          src/DeliveryType.cxx
          src/GenericFunctions.cxx
          src/StringUtils.cxx
          src/Clock.cxx
   src/RunStatusChecker.cxx
  PUBLIC_LINK_LIBRARIES O2::Headers O2::CommonUtils O2::CCDB
                        O2::DetectorsCalibration Microsoft.GSL::GSL)

o2_target_root_dictionary(
  DetectorsDCS
  HEADERS include/DetectorsDCS/DataPointCompositeObject.h
          include/DetectorsDCS/DataPointIdentifier.h
          include/DetectorsDCS/DataPointValue.h
   include/DetectorsDCS/RunStatusChecker.h)

if(OpenMP_CXX_FOUND)
  target_compile_definitions(${targetName} PRIVATE WITH_OPENMP)
  target_link_libraries(${targetName} PRIVATE OpenMP::OpenMP_CXX)
endif()

if(BUILD_TESTING)
  o2_add_test(
    data-point-types
    SOURCES test/testDataPointTypes.cxx
    COMPONENT_NAME dcs
    LABELS "dcs"
    PUBLIC_LINK_LIBRARIES O2::Framework O2::DetectorsDCS)
  o2_add_test(
    alias-expander
    SOURCES test/testAliasExpander.cxx
    COMPONENT_NAME dcs
    LABELS "dcs"
    PUBLIC_LINK_LIBRARIES O2::Framework O2::DetectorsDCS)
  o2_add_test(
    data-point-generator
    SOURCES test/testDataPointGenerator.cxx
    COMPONENT_NAME dcs
    LABELS "dcs"
    PUBLIC_LINK_LIBRARIES O2::Framework O2::DetectorsDCS)
  add_subdirectory(testWorkflow/macros)
endif()

add_subdirectory(testWorkflow)
