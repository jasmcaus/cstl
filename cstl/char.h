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

#ifndef CSTL_CHAR_H
#define CSTL_CHAR_H

#include <cstl/types.h>
#include <cstl/math.h>
#include <cstl/debug.h>

bool char_is_upper(char c);
bool char_is_lower(char c);
bool char_is_digit(char c);
bool char_is_alpha(char c);
bool char_is_alphanumeric(char c);
bool char_is_octal_digit(char c);
bool char_is_binary_digit(char c);
bool char_is_hex_digit(char c);
bool char_is_letter(char c);
char char_to_lower(char c);
char char_to_upper(char c) ;
bool char_is_whitespace(char c);
Int32 digit_to_int(char c);
Int32 hexdigit_to_int(char c);
char* char_first_occurence(char* str, char ch);
char* char_last_occurence(char* str, char ch);

#endif // CSTL_CHAR_H