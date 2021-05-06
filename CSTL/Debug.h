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

#ifndef CSTL_DEBUG_H
#define CSTL_DEBUG_H

#ifdef __cplusplus
namespace cstl {
extern "C" {
#endif

// Debug + Asserts  ==========================================
#ifndef CSTL_CHECK
    #define CSTL_CHECK3(cond, msg)       typedef char static_assertion_##msg[(!!(cond))*2-1]
    // NOTE(jasmcaus): Token pasting madness!!
    #define CSTL_CHECK2(cond, line)      CSTL_CHECK3(cond, static_assertion_at_line_##line)
    #define CSTL_CHECK1(cond, line)      CSTL_CHECK2(cond, line)
    #define CSTL_CHECK(cond)             CSTL_CHECK1(cond, __LINE__)
#endif


#ifdef __cplusplus
} // extern "C"
} // namespace cstl
#endif

#endif // CSTL_DEBUG_H
