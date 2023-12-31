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

o2_add_library(Headers
               SOURCES src/DataHeader.cxx src/NameHeader.cxx
                       src/HeartbeatFrame.cxx src/TimeStamp.cxx
                       src/DAQID.cxx src/RDHAny.cxx src/STFHeader.cxx
               PUBLIC_LINK_LIBRARIES O2::MemoryResources
                                     O2::GPUCommon)

o2_add_test(DataHeader
            SOURCES test/testDataHeader.cxx
            PUBLIC_LINK_LIBRARIES O2::Headers
            COMPONENT_NAME Headers
            LABELS dataformats)

o2_add_test(TimeStamp
            SOURCES test/testTimeStamp.cxx
            PUBLIC_LINK_LIBRARIES O2::Headers
            COMPONENT_NAME Headers
            LABELS dataformats)

o2_add_test(HeartbeatFrame
            SOURCES test/test_HeartbeatFrame.cxx
            PUBLIC_LINK_LIBRARIES O2::Headers
            COMPONENT_NAME Headers
            LABELS dataformats)

o2_add_test(RAWDataHeader
            SOURCES test/test_RAWDataHeader.cxx
            PUBLIC_LINK_LIBRARIES O2::Headers
            LABELS dataformats
            COMPONENT_NAME Headers)

o2_add_test(DAQID
            SOURCES test/testDAQID.cxx
            PUBLIC_LINK_LIBRARIES O2::Headers
            COMPONENT_NAME Headers
            LABELS dataformats)
