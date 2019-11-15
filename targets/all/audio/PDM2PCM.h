/*
 * Copyright (c) 2019 triaxis s.r.o.
 * Licensed under the MIT license. See LICENSE.txt file in the repository root
 * for full license information.
 *
 * audio/PDM2PCM.h
 *
 * Simple and fast PDM to PCM decimator
 */

#pragma once

#include <base/base.h>

namespace audio
{

class PDM2PCM
{
public:
    //! Resets the state of the decimator
    void Reset();
    //! Decimates the PDM input, generating 1 16-bit PCM output sample per 64 input bits
    const uint8_t* Decimate64(const uint8_t *pSrc, int16_t* pDst, int gain, size_t samples);
    //! Decimates the PDM input, generating 1 32-bit FP sample per 64 input bits
    const uint8_t* Decimate64(const uint8_t *pSrc, float* pDst, float gain, size_t samples);

private:
    struct State
    {
        uint32_t s0, s1, s2, s3;
    } state;
};

}
