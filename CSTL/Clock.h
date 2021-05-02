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

#ifndef CSTL_CLOCK_H
#define CSTL_CLOCK_H

#include <CSTL/Misc.h>
#include <CSTL/Types.h>

#ifdef __cplusplus
extern "C" {
#endif

// Time ==========================================
CSTL_DEF UInt64  gb_rdtsc        (void);
CSTL_DEF Float64  gb_time_now    (void); // This is only for relative time e.g. game loops
CSTL_DEF UInt64  gb_utc_time_now (void); // Number of microseconds since 1601-01-01 UTC
CSTL_DEF void gb_sleep_ms        (UInt32 ms);

#if defined(__cplusplus)
}
#endif

#endif // CSTL_CLOCK_H