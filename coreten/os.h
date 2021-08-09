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

#ifndef CORETEN_OS_H
#define CORETEN_OS_H

#include <coreten/buffer.h>
#include <coreten/os_defs.h>
#include <coreten/types.h>

#if defined(CORETEN_OS_POSIX)
    #define _XOPEN_SOURCE 700
    #include <unistd.h>
#endif // CORETEN_OS_POSIX

#if defined(CORETEN_OS_WINDOWS)
    #include <direct.h>
#endif // CORETEN_OS_WINDOWS

static cstlBuffer* os_get_cwd();
static cstlBuffer* os_path_dirname(cstlBuffer* path);
static cstlBuffer* os_path_extname(cstlBuffer* path);
static cstlBuffer* os_path_join(cstlBuffer* path1, cstlBuffer* path2);
static bool os_is_sep(char ch);
static bool os_path_is_abs(cstlBuffer* path);
static bool os_path_is_rel(cstlBuffer* path);
static bool os_path_is_root(cstlBuffer* path);

#ifndef CORETEN_OS_FUNC_ALIASES
    #define CORETEN_OS_FUNC_ALIASES
    #define ospd    os_path_dirname
    #define ospb    os_path_basename
    #define ospj    os_path_join
#endif // CORETEN_OS_FUNC_ALIASES

#endif // CORETEN_OS_H