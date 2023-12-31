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

/// \author Gabriele Gaetano Fronzé, gfronze@cern.ch

#include "DPLOutputTest.h"
#include <fstream>
#include "DPLUtils/Utils.h"
#include "Framework/DataProcessorSpec.h"
#include "random"
#include "Framework/Logger.h"
#include "Framework/ControlService.h"

namespace o2f = o2::framework;

namespace o2::workflows
{

o2f::DataProcessorSpec defineTestGenerator()
{
  return {"Generator",                                                  // Device name
          {},                                                           // No inputs for a generator
          o2f::Outputs{{"TST", "ToSink", 0, o2f::Lifetime::Timeframe}}, // One simple output

          o2f::AlgorithmSpec{[](o2f::InitContext&) {
            int msgCounter = 0;
            auto msgCounter_shptr = std::make_shared<int>(msgCounter);

            LOG(info) << ">>>>>>>>>>>>>> Generator initialised\n";

            // Processing context in captured from return on InitCallback
            return [msgCounter_shptr](o2f::ProcessingContext& ctx) {
              int msgIndex = (*msgCounter_shptr)++;
              if (msgIndex > 10) {
                ctx.services().get<framework::ControlService>().endOfStream();
              }
              LOG(info) << ">>> MSG:" << msgIndex << "\n";

              LOG(info) << ">>> Preparing MSG:" << msgIndex;

              auto& outputMsg = ctx.outputs().newChunk({"TST", "ToSink", 0, o2f::Lifetime::Timeframe},
                                                       (31 + 1) * sizeof(uint32_t) / sizeof(char));

              LOG(info) << ">>> Preparing1 MSG:" << msgIndex;

              auto payload = reinterpret_cast<uint32_t*>(outputMsg.data());

              payload[0] = msgIndex;

              LOG(info) << ">>> Preparing2 MSG:" << msgIndex;

              for (int k = 0; k < 31; ++k) {
                payload[k + 1] = (uint32_t)k;
                LOG(info) << ">>>>\t" << payload[k + 1];
              }

              LOG(info) << ">>> Done MSG:" << msgIndex;
            };
          }}};
}

o2f::DataProcessorSpec defineTestSink()
{
  return {"Sink",                                                               // Device name
          o2f::Inputs{{"input", "TST", "ToSink", 0, o2f::Lifetime::Transient}}, // No inputs, for the moment
          {},

          o2f::AlgorithmSpec{[](o2f::InitContext&) {
            LOG(info) << ">>>>>>>>>>>>>> Sink initialised\n";

            // Processing context in captured from return on InitCallback
            return [](o2f::ProcessingContext& ctx) {
              auto inputMsg = ctx.inputs().getByPos(0);
              auto payload = reinterpret_cast<const uint32_t*>(inputMsg.payload);

              LOG(info) << "Received message containing" << payload[0] << "elements\n";
              for (int j = 0; j < payload[0]; ++j) {
                LOG(info) << payload[j];
              }
            };
          }}};
}

o2::framework::WorkflowSpec DPLOutputTest()
{
  auto lspec = o2f::WorkflowSpec();

  // A generator of data
  lspec.emplace_back(defineTestGenerator());
  lspec.emplace_back(defineTestSink());
  return std::move(lspec);
}

} // namespace o2::workflows
