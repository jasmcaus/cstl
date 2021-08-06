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

#ifndef CSTL_CLOCK_H
#define CSTL_CLOCK_H

#include <time.h>

static double now();
static double duration(clock_t start, clock_t end);

// Returns the current time (in clock_t)
static double now() {
    return clock();
}

// Get duration between `start` and `end` in seconds.
static double duration(clock_t start, clock_t end) {
    return (double)(end - start)/CLOCKS_PER_SEC;
}

#endif // CSTL_CLOCK_H