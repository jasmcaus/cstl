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

#include <coreten/clock.h>

// Returns the current time (in clock_t)
double now() {
    return clock();
}

// Get duration between `start` and `end` in seconds.
double duration(clock_t start, clock_t end) {
    return (double)(end - start)/CLOCKS_PER_SEC;
}