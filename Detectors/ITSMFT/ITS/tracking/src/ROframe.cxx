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
///
/// \file ROframe.cxx
/// \brief
///

#include "ITStracking/ROframe.h"

#include <iostream>

namespace o2
{
namespace its
{

ROframe::ROframe(int ROframeId, int nLayers) : mROframeId{ROframeId}
{
  mClusters.resize(nLayers);
  mTrackingFrameInfo.resize(nLayers);
  // mClusterLabels.resize(nLayers);
  mClusterExternalIndices.resize(nLayers);
}

void ROframe::addPrimaryVertex(const float xCoordinate, const float yCoordinate, const float zCoordinate)
{
  mPrimaryVertices.emplace_back(float3{xCoordinate, yCoordinate, zCoordinate});
}

void ROframe::addPrimaryVertices(std::vector<Vertex> vertices)
{
  for (Vertex& vertex : vertices) {
    mPrimaryVertices.emplace_back(float3{vertex.getX(), vertex.getY(), vertex.getZ()});
  }
}

void ROframe::printPrimaryVertices() const
{
  const int verticesNum{static_cast<int>(mPrimaryVertices.size())};

  for (int iVertex{0}; iVertex < verticesNum; ++iVertex) {

    const float3& currentVertex = mPrimaryVertices[iVertex];
    std::cout << "-1\t" << currentVertex.x << "\t" << currentVertex.y << "\t" << currentVertex.z << std::endl;
  }
}

int ROframe::getTotalClusters() const
{
  size_t totalClusters{0};
  for (auto& clusters : mClusters) {
    totalClusters += clusters.size();
  }
  return int(totalClusters);
}
} // namespace its
} // namespace o2
