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

o2_add_library(Field
               SOURCES src/MagFieldContFact.cxx
                       src/MagFieldFact.cxx
                       src/MagFieldFast.cxx
                       src/MagFieldParam.cxx
                       src/MagneticField.cxx
                       src/MagneticWrapperChebyshev.cxx
                       src/ALICE3MagneticField.cxx
                       PUBLIC_LINK_LIBRARIES O2::MathUtils FairRoot::Base O2::CommonUtils)

o2_target_root_dictionary(Field
                          HEADERS include/Field/MagneticWrapperChebyshev.h
                                  include/Field/MagneticField.h
                                  include/Field/MagFieldParam.h
                                  include/Field/MagFieldContFact.h
                                  include/Field/MagFieldFast.h
                                  include/Field/MagFieldFact.h
                                  include/Field/ALICE3MagneticField.h)

o2_add_test(MagneticField
            SOURCES test/testMagneticField.cxx
            PUBLIC_LINK_LIBRARIES O2::Field
            COMPONENT_NAME Field
            LABELS field
            ENVIRONMENT O2_ROOT=${CMAKE_BINARY_DIR}/stage)

o2_add_test_root_macro(macro/extractMapsAsText.C
                       PUBLIC_LINK_LIBRARIES O2::Field
                       LABELS field)

o2_add_test_root_macro(macro/createMapsFromText.C
                       PUBLIC_LINK_LIBRARIES O2::Field
                       LABELS field)
