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
#ifndef ALICEO2_PHOS_RAWBUFFER_H
#define ALICEO2_PHOS_RAWBUFFER_H

#include <array>
#include <cstdint>
#include <iosfwd>
#include <gsl/span>

namespace o2
{
namespace phos
{

/// \class RawBuffer
/// \brief Buffer for PHOS raw pages
/// \ingroup PHOSreconstruction
/// \author Dmitri Peresunko after Markus Fasel
/// \since Sept, 2020
class RawBuffer
{
 public:
  RawBuffer() = default;
  ~RawBuffer() = default;

  void reset() { mCurrentDataWord = 0; }

  /// \brief Flush the buffer
  /// Does not overwrite the word buffer but just resets the counter and iterator
  void flush();

  /// \brief Read page from stream
  /// \param in Input file stream
  /// \param payloadsize Number of char words in payload
  /// Read a whole superpage from the raw stream
  /// and convert the bitwise representation directly
  /// into 32 bit words
  void readFromStream(std::istream& in, uint32_t payloadsize);

  /// \brief Read page from raw memory buffer
  /// \param rawmemory Raw memory buffer (as char words) with size of the payload from the raw data header
  /// Converts the char word raw memory buffer of a pages into
  /// into the 32 bit word buffer
  void readFromMemoryBuffer(const gsl::span<const char> rawmemory);

  /// \brief Get the number of data words read for the superpage
  /// \return Number of data words in the superpage
  int getNDataWords() const { return mNDataWords; }

  /// \brief Get all data words from the raw buffer
  /// \return Span with data words in the buffer (removing trailing null entries)
  const gsl::span<const uint32_t> getDataWords() const { return gsl::span<const uint32_t>(mDataWords.data(), mNDataWords); }

  /// \brief Check whether the next data word exists
  /// \return True if more data words exist, false otherwise
  /// Check is done starting from the current position
  /// of the iterator
  bool hasNext() const { return mCurrentDataWord < mNDataWords; }

 private:
  std::array<uint32_t, 2048> mDataWords; ///< Data words in one superpage
  int mNDataWords = 0;                   ///< Number of data words read from superpage
  int mCurrentDataWord = 0;              ///< Iterator over words in superpage
};

} // namespace phos

} // namespace o2

#endif