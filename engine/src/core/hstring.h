#pragma once

#include "defines.h"

// Returns the length of the given string.
HAPI u64 string_length(const char* str);

HAPI char* string_duplicate(const char* str);

// Case-sensitive string comparison. True if the same, otherwise false.
HAPI b8 strings_equal(const char* str0, const char* str1);
