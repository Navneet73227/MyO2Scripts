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
#ifndef O2_FRAMEWORK_OUTPUTSPEC_H_
#define O2_FRAMEWORK_OUTPUTSPEC_H_

#include "Headers/DataHeader.h"
#include "Framework/Lifetime.h"
#include "Framework/ConcreteDataMatcher.h"
#include "Framework/ConfigParamSpec.h"

#if !defined(__CLING__) && !defined(__ROOTCLING__)
#include <variant>
#endif

namespace o2::framework
{

struct OutputLabel {
  std::string value;
};

/// A criteria which matches data being produced by a given DataProcessorSpec.
/// This needs to be declared upfront so that we can automatically build the
/// topology.
struct OutputSpec {
  OutputLabel binding;
#if !defined(__CLING__) && !defined(__ROOTCLING__)
  std::variant<ConcreteDataMatcher, ConcreteDataTypeMatcher> matcher;
#endif
  enum Lifetime lifetime = Lifetime::Timeframe;

  /// Build a fully qualified tuple for the OutputSpec
  OutputSpec(OutputLabel const& inBinding, header::DataOrigin inOrigin, header::DataDescription inDescription,
             header::DataHeader::SubSpecificationType inSubSpec,
             enum Lifetime lifetime_ = Lifetime::Timeframe,
             std::vector<ConfigParamSpec> const& metadata_ = {});

  /// Build a fully qualified tuple for the OutputSpec
  OutputSpec(header::DataOrigin inOrigin, header::DataDescription inDescription,
             header::DataHeader::SubSpecificationType inSubSpec,
             enum Lifetime lifetime_ = Lifetime::Timeframe,
             std::vector<ConfigParamSpec> const& metadata_ = {});

  /// Build an OutputSpec which has 0 as subSpec.
  OutputSpec(OutputLabel const& inBinding, header::DataOrigin inOrigin, header::DataDescription inDescription,
             enum Lifetime lifetime_ = Lifetime::Timeframe,
             std::vector<ConfigParamSpec> const& metadata_ = {});

  /// Build an OutputSpec which has 0 as subSpec.
  OutputSpec(header::DataOrigin inOrigin, header::DataDescription inDescription,
             enum Lifetime lifetime_ = Lifetime::Timeframe,
             std::vector<ConfigParamSpec> const& metadata_ = {});

  /// Build an OutputSpec from a ConcreteDataMatcher
  OutputSpec(OutputLabel const& inBinding, ConcreteDataMatcher const& concrete,
             enum Lifetime lifetime_ = Lifetime::Timeframe,
             std::vector<ConfigParamSpec> const& metadata_ = {});

  /// Build an OutputSpec from a ConcreteDataMatcher
  OutputSpec(ConcreteDataMatcher const& concrete,
             enum Lifetime lifetime_ = Lifetime::Timeframe,
             std::vector<ConfigParamSpec> const& metadata_ = {});

  /// Build an OutputSpec which does not specify which subSpec the output will
  /// have.
  OutputSpec(OutputLabel const& inBinding, ConcreteDataTypeMatcher const& dataType,
             enum Lifetime lifetime_ = Lifetime::Timeframe,
             std::vector<ConfigParamSpec> const& metadata_ = {});

  /// Build an OutputSpec which does not specify which subSpec the output will
  /// have.
  OutputSpec(ConcreteDataTypeMatcher const& dataType,
             enum Lifetime lifetime_ = Lifetime::Timeframe,
             std::vector<ConfigParamSpec> const& metadata_ = {});

  bool operator==(OutputSpec const& that) const;

  /// A set of configurables which can be used to customise the InputSpec.
  std::vector<ConfigParamSpec> metadata;

  friend std::ostream& operator<<(std::ostream& stream, OutputSpec const& arg);
};

} // namespace o2::framework
#endif
