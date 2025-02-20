#ifndef NH_CORE_STRING_H
#define NH_CORE_STRING_H

#ifndef DOXYGEN_SHOULD_SKIP_THIS

/**
 * Netzhaut - Web Browser Engine
 * Copyright (C) 2022  Dajo Frey
 * Published under GNU LGPL. See Netzhaut/LICENSE.LGPL file.
 */

#include "Array.h"

#include "../Common/Includes.h"

#include <stdint.h>
#include <stddef.h>

#endif

/** 
  * A string is an array of char's. 
  */ 
 typedef nh_core_Array nh_core_String; 

 /** 
  * An ASCII string is a string. 
  */ 
 typedef nh_core_String nh_ASCIIString; 

/** @addtogroup lib_nh-core_enums
 *  @{
 */

    typedef enum NH_ESCAPE {
        NH_ESCAPE_START      = 1,
        NH_ESCAPE_CSI        = 2,
        NH_ESCAPE_STR        = 4,  /* OSC, PM, APC */
        NH_ESCAPE_ALTCHARSET = 8,
        NH_ESCAPE_STR_END    = 16, /* a final string was encountered */
        NH_ESCAPE_TEST       = 32, /* Enter in test mode */
        NH_ESCAPE_UTF8       = 64,
        NH_ESCAPE_DCS        = 128,
    } NH_ESCAPE;

/** @} */

/** @addtogroup lib_nh-core_structs
 *  @{
 */

    typedef struct nh_DataStorageUnits {
        long long gigabytes;
        long long megabytes;
        long long kilobytes;
        long long bytes;
    } nh_DataStorageUnits;

/** @} */

/** @addtogroup lib_nh-core_functions
 *  @{
 */

    nh_DataStorageUnits nh_humanizeBytes(
        long long bytes
    );

    char *nh_core_allocateBytes(
        char *bytes_p
    );

    int nh_levenshteinDistance(
        char *s1_p, char *s2_p, bool caseSensitive
    );

    nh_core_String nh_core_initString(
        int chunkSize
    );

    NH_API_RESULT nh_core_appendByteToString(
        nh_core_String *String_p, char byte
    );

    NH_API_RESULT nh_core_appendByteToStringRepeatedly(
        nh_core_String *String_p, char byte, int count
    );

    NH_API_RESULT nh_core_appendToString(
        nh_core_String *String_p, char *bytes_p, int length
    );

    NH_API_RESULT nh_core_appendFormatToString(
        nh_core_String *String_p, char *format_p, ...
    );
    
    NH_API_RESULT nh_core_removeFromString(
        nh_core_String *String_p, int index, unsigned int count
    );

    NH_API_RESULT nh_core_removeTailFromString(
        nh_core_String *String_p, unsigned int count
    );

    void nh_core_freeString(
        nh_core_String *String_p
    );

/** @} */

#endif 
