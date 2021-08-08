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

#ifndef CSTL_CORE_CSTL_H
#define CSTL_CORE_CSTL_H

/** 
    Jason Dsouza's (jasmcaus) C Helper Library 
    Available in the public domain
    Use at your own risk - no warranty implied

    This is a single header file that replaces (and makes modern) a bunch of useful stuff from 
    the C/C++ Standard Library

LICENSE
	This software is dual-licensed to the public domain and under the following license: you are 
    granted a perpetual, irrevocable license to copy, modify, 	publish, and distribute this file 
    as you see fit.

WARNING
	- This library is **slightly** experimental and features may not work as expected.
	- This also means that many functions are not documented.
CREDITS
	Written by Jason Dsouza <@jasmcaus>
*/

/*
    NOTE: Do not include this file multiple times (in separate source files)
    Since this is a header-only library (with no implementation source file), each time you include this file, 
    methods are individually built into their separate object files.
    Thus, you will end up with the "Multiple definition of `function`" error. 

    If you need to use an individual file, either include this file (adcore.h) _once_ or pick and choose what you need - 
    being explicit never hurts. 

    For the development of the Adorad Language, it is required (otherwise you'll run into compilation problems such as the 
    one above) you choose the latter option. 
    
    Reminder: Be Explicit. 
*/

#include <cstl/os_defs.h>
#include <cstl/cpu.h>
#include <cstl/compilers.h>
#include <cstl/types.h>
#include <cstl/headers.h>
#include <cstl/clock.h>
#include <cstl/debug.h>
#include <cstl/misc.h>
#include <cstl/io.h>
#include <cstl/memory.h>
#include <cstl/math.h>
#include <cstl/os.h>
#include <cstl/buffer.h>
#include <cstl/char.h>
#include <cstl/utf8.h>
#include <cstl/vector.h>

#ifdef CSTL_INCLUDE_HASH_H
    #include <cstl/hash.h>
#endif // CSTL_INCLUDE_HASH_H

#ifdef CSTL_INCLUDE_WINDOWS_H
    #include <cstl/windows.h>
#endif // CSTL_INCLUDE_WINDOWS_H

#endif // CSTL_CORE_CSTL_H