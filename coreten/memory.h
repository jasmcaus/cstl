/*
  ______ ____ ________ _
 / ____/ ____|__   __/| |
| |    | (_     | |   | |      CSTL - The Coreten Standard Library
| |    \___ \   | |   | |      Languages: C, C++ and Assembly
| |___ ____) |  | |   | |____  https://github.com/jasmcaus/cstl
 \_____\_____/  |_|   \______| 

Licensed under the MIT License <http://opensource.org/licenses/MIT>
SPDX-License-Identifier: MIT
Copyright (c) 2021 Jason Dsouza <@jasmcaus>
*/

#ifndef CORETEN_MEMORY_H
#define CORETEN_MEMORY_H

#ifndef KB_TO_BYTES
    #define KB_TO_BYTES(x)               (x) * (Int64)(1024)
    #define MB_TO_BYTES(x)    KB_TO_BYTES(x) * (Int64)(1024)
    #define GB_TO_BYTES(x)    MB_TO_BYTES(x) * (Int64)(1024)
    #define TB_TO_BYTES(x)    GB_TO_BYTES(x) * (Int64)(1024)
#endif 

#define CORETEN_ONES            cast(Ull)-1/UInt8_MAX
#define CORETEN_HIGHS           CORETEN_ONES * (UInt8_MAX/2+1)
#define CORETEN_HAS_ZERO(x)     (x)-CORETEN_ONES & ~(x) & CORETEN_HIGHS

#endif // CORETEN_MEMORY_H