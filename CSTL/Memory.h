/*
  ______ ____ ________ _
 / ____/ ____|__   __/| |
| |    | (_     | |   | |      CSTL - The neatest rewrite of the C/C++ Standard Library
| |    \___ \   | |   | |      Language: C
| |___ ____) |  | |   | |____  https://github.com/jasmcaus/CSTL
 \_____\_____/  |_|   \______| 

Licensed under the MIT License <http://opensource.org/licenses/MIT>
SPDX-License-Identifier: MIT
Copyright (c) 2021 Jason Dsouza <http://github.com/jasmcaus>
*/

#ifndef CSTL_MEMORY_H
#define CSTL_MEMORY_H

#ifdef __cplusplus
namespace cstl {
extern "C" {
#endif

// Memory ==========================================
#ifndef KB_TO_BYTES
    #define KB_TO_BYTES(x)            (x) * (Int64)(1024)
    #define MB_TO_BYTES(x) KB_TO_BYTES(x) * (Int64)(1024)
    #define GB_TO_BYTES(x) MB_TO_BYTES(x) * (Int64)(1024)
    #define TB_TO_BYTES(x) GB_TO_BYTES(x) * (Int64)(1024)
#endif 

#define CSTL__ONES        cast(Ull)-1/UInt8_MAX
#define CSTL__HIGHS       CSTL__ONES * (UInt8_MAX/2+1)
#define CSTL__HAS_ZERO(x) (x)-CSTL__ONES & ~(x) & CSTL__HIGHS


#ifdef __cplusplus
} // extern "C"
} // namespace cstl
#endif

#endif // CSTL_MEMORY_H