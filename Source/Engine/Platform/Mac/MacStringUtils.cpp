// Copyright (c) 2012-2021 Wojciech Figat. All rights reserved.

#if PLATFORM_MAC

#include "Engine/Platform/StringUtils.h"
#include <wctype.h>
#include <cctype>
#include <wchar.h>
#include <cstring>
#include <stdlib.h>

bool StringUtils::IsUpper(char c)
{
    return isupper(c) != 0;
}

bool StringUtils::IsLower(char c)
{
    return islower(c) != 0;
}

bool StringUtils::IsAlpha(char c)
{
    return iswalpha(c) != 0;
}

bool StringUtils::IsPunct(char c)
{
    return ispunct(c) != 0;
}

bool StringUtils::IsAlnum(char c)
{
    return isalnum(c) != 0;
}

bool StringUtils::IsDigit(char c)
{
    return isdigit(c) != 0;
}

bool StringUtils::IsHexDigit(char c)
{
    return isxdigit(c) != 0;
}

bool StringUtils::IsWhitespace(char c)
{
    return isspace(c) != 0;
}

char StringUtils::ToUpper(char c)
{
    return toupper(c);
}

char StringUtils::ToLower(char c)
{
    return tolower(c);
}

bool StringUtils::IsUpper(Char c)
{
    return iswupper(c) != 0;
}

bool StringUtils::IsLower(Char c)
{
    return iswlower(c) != 0;
}

bool StringUtils::IsAlpha(Char c)
{
    return iswalpha(c) != 0;
}

bool StringUtils::IsPunct(Char c)
{
    return iswpunct(c) != 0;
}

bool StringUtils::IsAlnum(Char c)
{
    return iswalnum(c) != 0;
}

bool StringUtils::IsDigit(Char c)
{
    return iswdigit(c) != 0;
}

bool StringUtils::IsHexDigit(Char c)
{
    return iswxdigit(c) != 0;
}

bool StringUtils::IsWhitespace(Char c)
{
    return iswspace(c) != 0;
}

Char StringUtils::ToUpper(Char c)
{
    return towupper(c);
}

Char StringUtils::ToLower(Char c)
{
    return towlower(c);
}

int32 StringUtils::Compare(const Char* str1, const Char* str2)
{
    Char c1, c2;
    int32 i;
    do
    {
        c1 = *str1++;
        c2 = *str2++;
        i = (int32)c1 - (int32)c2;
    } while (i == 0 && c1 && c2);
    return i;
}

int32 StringUtils::Compare(const Char* str1, const Char* str2, int32 maxCount)
{
    Char c1, c2;
    int32 i;
    if (maxCount == 0)
        return 0;
    do
    {
        c1 = *str1++;
        c2 = *str2++;
        i = (int32)c1 - (int32)c2;
        maxCount--;
    } while (i == 0 && c1 && c2 && maxCount);
    return i;
}

int32 StringUtils::CompareIgnoreCase(const Char* str1, const Char* str2)
{
    Char c1, c2;
    int32 i;
    do
    {
        c1 = ToLower(*str1++);
        c2 = ToLower(*str2++);
        i = (int32)c1 - (int32)c2;
    } while (i == 0 && c1 && c2);
    return i;
}

int32 StringUtils::CompareIgnoreCase(const Char* str1, const Char* str2, int32 maxCount)
{
    Char c1, c2;
    int32 i;
    if (maxCount == 0)
        return 0;
    do
    {
        c1 = ToLower(*str1++);
        c2 = ToLower(*str2++);
        i = (int32)c1 - (int32)c2;
        maxCount--;
    } while (i == 0 && c1 && c2 && maxCount);
    return i;
}

int32 StringUtils::Length(const Char* str)
{
    if (!str)
        return 0;
    const Char* ptr = str;
    for (; *ptr; ++ptr)
    {
    }
    return ptr - str;
}

int32 StringUtils::Length(const char* str)
{
    if (!str)
        return 0;
    return static_cast<int32>(strlen(str));
}

int32 StringUtils::Compare(const char* str1, const char* str2)
{
    return strcmp(str1, str2);
}

int32 StringUtils::Compare(const char* str1, const char* str2, int32 maxCount)
{
    return strncmp(str1, str2, maxCount);
}

int32 StringUtils::CompareIgnoreCase(const char* str1, const char* str2)
{
    return strcasecmp(str1, str2);
}

int32 StringUtils::CompareIgnoreCase(const char* str1, const char* str2, int32 maxCount)
{
    return strncasecmp(str1, str2, maxCount);
}

Char* StringUtils::Copy(Char* dst, const Char* src)
{
    Char* q = dst;
    const Char* p = src;
    Char ch;
    do
    {
        *q++ = ch = *p++;
    } while (ch);
    return dst;
}

Char* StringUtils::Copy(Char* dst, const Char* src, int32 count)
{
    Char* q = dst;
    const Char* p = src;
    char ch;
    while (count)
    {
        count--;
        *q++ = ch = *p++;
        if (!ch)
            break;
    }
    *q = 0;
    return dst;
}

const Char* StringUtils::Find(const Char* str, const Char* toFind)
{
    while (*str)
    {
        const Char* start = str;
        const Char* sub = toFind;

        // If first character of sub string match, check for whole string
        while (*str && *sub && *str == *sub)
        {
            str++;
            sub++;
        }

        // If complete substring match, return starting address
        if (!*sub)
            return (Char*)start;

        // Increment main string 
        str = start + 1;
    }

    // No matches
    return nullptr;
}

const char* StringUtils::Find(const char* str, const char* toFind)
{
    return strstr(str, toFind);
}

void StringUtils::ConvertANSI2UTF16(const char* from, Char* to, int32 len)
{
    todo;
}

void StringUtils::ConvertUTF162ANSI(const Char* from, char* to, int32 len)
{
    todo;
}

#endif
