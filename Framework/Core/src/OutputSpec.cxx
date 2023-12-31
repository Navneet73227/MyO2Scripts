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

#include "Framework/OutputSpec.h"
#include "Framework/Lifetime.h"

namespace o2::framework
{
OutputSpec::OutputSpec(OutputLabel const& inBinding, header::DataOrigin inOrigin, header::DataDescription inDescription,
                       header::DataHeader::SubSpecificationType inSubSpec,
                       enum Lifetime inLifetime,
                       std::vector<ConfigParamSpec> const& metadata_)
  : binding{inBinding},
    matcher{ConcreteDataMatcher{inOrigin, inDescription, inSubSpec}},
    lifetime{inLifetime},
    metadata{metadata_}
{
}

OutputSpec::OutputSpec(header::DataOrigin inOrigin, header::DataDescription inDescription,
                       header::DataHeader::SubSpecificationType inSubSpec,
                       enum Lifetime inLifetime,
                       std::vector<ConfigParamSpec> const& metadata_)
  : binding{OutputLabel{""}},
    matcher{ConcreteDataMatcher{inOrigin, inDescription, inSubSpec}},
    lifetime{inLifetime},
    metadata{metadata_}
{
}

OutputSpec::OutputSpec(OutputLabel const& inBinding, header::DataOrigin inOrigin, header::DataDescription inDescription,
                       enum Lifetime inLifetime,
                       std::vector<ConfigParamSpec> const& metadata_)
  : binding{inBinding},
    // Note: using 0 as subspec is specifically intended default behavior, a matcher ignoring
    // the subspec can be passed using the specific constructor with ConcreteDataTypeMatcher
    matcher{ConcreteDataMatcher{inOrigin, inDescription, 0}},
    lifetime{inLifetime},
    metadata{metadata_}
{
}

OutputSpec::OutputSpec(header::DataOrigin inOrigin, header::DataDescription inDescription,
                       enum Lifetime inLifetime,
                       std::vector<ConfigParamSpec> const& metadata_)
  : binding{OutputLabel{""}},
    // Note: using 0 as subspec is specifically intended default behavior, a matcher ignoring
    // the subspec can be passed using the specific constructor with ConcreteDataTypeMatcher
    matcher{ConcreteDataMatcher{inOrigin, inDescription, 0}},
    lifetime{inLifetime},
    metadata{metadata_}
{
}

OutputSpec::OutputSpec(ConcreteDataMatcher const& concrete,
                       enum Lifetime inLifetime,
                       std::vector<ConfigParamSpec> const& metadata_)
  : binding{""},
    matcher{concrete},
    lifetime{inLifetime},
    metadata{metadata_}
{
}

OutputSpec::OutputSpec(OutputLabel const& inBinding, ConcreteDataMatcher const& concrete,
                       enum Lifetime inLifetime,
                       std::vector<ConfigParamSpec> const& metadata_)
  : binding{inBinding},
    matcher{concrete},
    lifetime{inLifetime}
{
}

OutputSpec::OutputSpec(ConcreteDataTypeMatcher const& dataType,
                       enum Lifetime inLifetime,
                       std::vector<ConfigParamSpec> const& metadata_)
  : binding{OutputLabel{""}},
    matcher{dataType},
    lifetime{inLifetime},
    metadata{metadata_}
{
}

OutputSpec::OutputSpec(OutputLabel const& inBinding, ConcreteDataTypeMatcher const& dataType,
                       enum Lifetime inLifetime,
                       std::vector<ConfigParamSpec> const& metadata_)
  : binding{inBinding},
    matcher{dataType},
    lifetime{inLifetime},
    metadata{metadata_}
{
}

bool OutputSpec::operator==(OutputSpec const& that) const
{
  return this->matcher == that.matcher &&
         lifetime == that.lifetime;
};

} // namespace o2::framework
