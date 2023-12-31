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

o2_add_library(TOFReconstruction
               SOURCES src/DataReader.cxx src/Clusterer.cxx
                       src/ClustererTask.cxx src/Encoder.cxx
                       src/DecoderBase.cxx
                       src/Decoder.cxx
                       src/CTFCoder.cxx
                       src/CosmicProcessor.cxx
               PUBLIC_LINK_LIBRARIES O2::TOFBase O2::DataFormatsTOF
                                     O2::SimulationDataFormat
                                     O2::CommonDataFormat
                                     O2::DataFormatsTOF
                                     O2::rANS O2::DPLUtils
                                     O2::DetectorsRaw)

o2_target_root_dictionary(TOFReconstruction
                          HEADERS include/TOFReconstruction/DataReader.h
                                  include/TOFReconstruction/Clusterer.h
                                  include/TOFReconstruction/ClustererTask.h
                                  include/TOFReconstruction/Encoder.h
                                  include/TOFReconstruction/DecoderBase.h
                                  include/TOFReconstruction/Decoder.h
                                  include/TOFReconstruction/CosmicProcessor.h)
