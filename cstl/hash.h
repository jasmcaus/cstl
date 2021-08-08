/*
  ______ ____ ________ _
 / ____/ ____|__   __/| |
| |    | (_     | |   | |      CSTL - The neatest rewrite of the C/C++ Standard Library
| |    \___ \   | |   | |      Languages: C, C++ and Assembly
| |___ ____) |  | |   | |____  https://github.com/jasmcaus/cstl
 \_____\_____/  |_|   \______| 

Licensed under the MIT License <http://opensource.org/licenses/MIT>
SPDX-License-Identifier: MIT
Copyright (c) 2021 Jason Dsouza <@jasmcaus>
*/

#ifndef CSTL_HASH_H
#define CSTL_HASH_H

#include <cstl/types.h>
#include <cstl/os_defs.h>
#include <cstl/misc.h>

/*
    Hashing & Checksum Functions
*/

UInt32 hash_adler32(void const* data, Ll len);

UInt32 hash_crc32(void const* data, Ll len);
UInt64 hash_crc64(void const* data, Ll len);

UInt32 hash_fnv32 (void const* data, Ll len);
UInt64 hash_fnv64 (void const* data, Ll len);
UInt32 hash_fnv32a(void const* data, Ll len);
UInt64 hash_fnv64a(void const* data, Ll len);

// Default seed of 0x9747b28c
// I prefer using `murmur64` formost hashes
UInt32 hash_murmur32(void const* data, Ll len);
UInt64 hash_murmur64(void const* data, Ll len);

UInt32 hash_murmur32_seed(void const* data, Ll len, UInt32 seed);
UInt64 hash_murmur64_seed(void const* data__, Ll len, UInt64 seed);

#endif // CSTL_HASH_H