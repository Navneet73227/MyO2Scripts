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
#ifndef FRAMEWORK_INPUTSPEC_H
#define FRAMEWORK_INPUTSPEC_H

#include "Framework/Lifetime.h"
#include "Framework/ConcreteDataMatcher.h"
#include "Framework/DataDescriptorMatcher.h"
#include "Framework/ConfigParamSpec.h"

#include <string>
#include <ostream>
#if !defined(__CLING__) && !defined(__ROOTCLING__)
#include <variant>
#endif

namespace o2::framework
{

/// A selector for some kind of data being processed, either in
/// input or in output. This can be used, for example to match
/// specific payloads in a timeframe.
struct InputSpec {
  /// Create a fully qualified InputSpec
  InputSpec(std::string binding_,
            header::DataOrigin origin_,
            header::DataDescription description_,
            header::DataHeader::SubSpecificationType subSpec_,
            enum Lifetime lifetime_ = Lifetime::Timeframe,
            std::vector<ConfigParamSpec> const& metadata_ = {});
  /// Create a fully qualified InputSpec (alternative syntax)
  InputSpec(std::string binding_,
            ConcreteDataMatcher const& dataType,
            enum Lifetime lifetime_ = Lifetime::Timeframe,
            std::vector<ConfigParamSpec> const& metadata_ = {});
  /// Create a fully qualified InputSpec where the subSpec is 0
  InputSpec(std::string binding_,
            header::DataOrigin origin_,
            header::DataDescription description_,
            enum Lifetime lifetime_ = Lifetime::Timeframe,
            std::vector<ConfigParamSpec> const& metadata_ = {});
  /// Create an InputSpec which does not check for the subSpec.
  InputSpec(std::string binding_,
            ConcreteDataTypeMatcher const& dataType,
            enum Lifetime lifetime_ = Lifetime::Timeframe,
            std::vector<ConfigParamSpec> const& metadata_ = {});
  /// Create an InputSpec which does not check for the description and the subSpec.
  InputSpec(std::string binding_,
            header::DataOrigin const& dataType,
            enum Lifetime lifetime_ = Lifetime::Timeframe,
            std::vector<ConfigParamSpec> const& metadata_ = {});
  InputSpec(std::string binding,
            data_matcher::DataDescriptorMatcher&& matcher,
            enum Lifetime lifetime_ = Lifetime::Timeframe,
            std::vector<ConfigParamSpec> const& metadata_ = {});

  /// A mnemonic name for the input spec.
  std::string binding;

  /// The actual matcher for the input spec.
#if !defined(__CLING__) && !defined(__ROOTCLING__)
  std::variant<ConcreteDataMatcher, data_matcher::DataDescriptorMatcher> matcher;
#endif

  enum Lifetime lifetime;

  /// A set of configurables which can be used to customise the InputSpec.
  std::vector<ConfigParamSpec> metadata;

  friend std::ostream& operator<<(std::ostream& stream, InputSpec const& arg);
  bool operator==(InputSpec const& that) const;
};

} // namespace o2
#endif
