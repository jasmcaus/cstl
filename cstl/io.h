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

#ifndef CSTL_IO_H
#define CSTL_IO_H

#include <cstl/types.h>
#include <cstl/debug.h>

typedef struct File {
    char* full_path;
    char* basename;
    int fileid;

    char* contents;
} File;

char* readFile(const char* fname);
bool file_exists(const char* path);

#endif // CSTL_IO_H