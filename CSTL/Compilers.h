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

#ifndef CSTL_COMPILERS_H
#define CSTL_COMPILERS_H

#ifdef __cplusplus
extern "C" {
#endif

// Compilers ==========================================
// CSTL_COMPILER_...
#if defined(_MSC_VER)
    #define CSTL_COMPILER_MSVC 1
#elif defined(__GNUC__)
    #define CSTL_COMPILER_GCC 1
#elif defined(__clang__)
    #define CSTL_COMPILER_CLANG 1
#else 
    #error Unknown Compiler (Hazel currently supports only MSVC, GCC and Clang)
#endif 

#if defined(__cplusplus)
}
#endif

#endif // CSTL_COMPILERS_H