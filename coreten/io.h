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

#ifndef CORETEN_IO_H
#define CORETEN_IO_H

#include <coreten/types.h>
#include <coreten/debug.h>
#include <coreten/headers.h>

typedef struct File {
    char* full_path;
    char* basename;
    int fileid;

    char* contents;
} File;

char* readFile(const char* fname);
bool file_exists(const char* path);

#endif // CORETEN_IO_H