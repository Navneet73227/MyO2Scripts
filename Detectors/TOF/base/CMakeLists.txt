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

o2_add_library(TOFBase
               SOURCES src/Geo.cxx
                       src/Digit.cxx
                       src/CableLength.cxx
                       src/Mapping.cxx
                       src/Strip.cxx
                       src/WindowFiller.cxx
                       src/EventTimeMaker.cxx
                       src/Utils.cxx
                       src/CalibTOFapi.cxx
               PUBLIC_LINK_LIBRARIES Boost::serialization FairRoot::Base Microsoft.GSL::GSL
                                     O2::DetectorsBase O2::CommonDataFormat O2::DetectorsRaw
                                     O2::DataFormatsTOF)

o2_target_root_dictionary(TOFBase
                          HEADERS include/TOFBase/Geo.h include/TOFBase/Digit.h include/TOFBase/EventTimeMaker.h include/TOFBase/Utils.h
                                  include/TOFBase/Strip.h include/TOFBase/WindowFiller.h include/TOFBase/CalibTOFapi.h)

o2_add_test(TOFIndex
            SOURCES test/testTOFIndex.cxx
            COMPONENT_NAME TOF
            PUBLIC_LINK_LIBRARIES O2::TOFBase)
