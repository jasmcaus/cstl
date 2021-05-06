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

#ifndef _CSTL_CORE_CSTL_H
#define _CSTL_CORE_CSTL_H

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
	Written Jason Dsouza
*/

#ifndef CSTL_USING_CUSTOM_GENERATED_MACROS
    #include <CSTL/CMake_Macros.h>
#endif // CSTL_USING_CUSTOM_GENERATED_MACROS

#include <CSTL/Clock.h>
#include <CSTL/Compilers.h>
#include <CSTL/Cpus.h>
#include <CSTL/Debug.h>
#include <CSTL/Exception.h>
#include <CSTL/Headers.h>
#include <CSTL/IO.h>
#include <CSTL/Memory.h>
#include <CSTL/Misc.h>
#include <CSTL/OS.h>
#include <CSTL/String.h>
#include <CSTL/Types.h>

#endif // _CSTL_CORE_CSTL_H