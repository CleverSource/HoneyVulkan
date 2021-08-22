#pragma once

#include "defines.h"

// Disable assertions by commenting out the below line.
#define HASSERTIONS_ENABLED

#ifdef HASSERTIONS_ENABLED
    #if _MSC_VER
        #include <intrin.h>
        #define debugBreak() __debugbreak()
    #else
        #define debugBreak() __builtin_trap()
    #endif

    HAPI void report_assertion_failure(const char* expression, const char* message, const char* file, i32 line);

    #define HASSERT(expr)                                                \
        {                                                                \
            if (expr) {                                                  \
            } else {                                                     \
                report_assertion_failure(#expr, "", __FILE__, __LINE__); \
                debugBreak();                                            \
            }                                                            \
        }

    #define HASSERT_MSG(expr, message)                                        \
        {                                                                     \
            if (expr) {                                                       \
            } else {                                                          \
                report_assertion_failure(#expr, message, __FILE__, __LINE__); \
                debugBreak();                                                 \
            }                                                                 \
        }

    #ifdef _DEBUG
        #define HASSERT_DEBUG(expr)                                          \
            {                                                                \
                if (expr) {                                                  \
                } else {                                                     \
                    report_assertion_failure(#expr, "", __FILE__, __LINE__); \
                    debugBreak();                                            \
                }                                                            \
            }
    #else
        #define HASSERT_DEBUG(expr) // Does nothing at all
    #endif
#else
    #define HASSERT(expr)              // Does nothing at all
    #define HASSERT_MSG(expr, message) // Does nothing at all
    #define HASSERT_DEBUG(expr)        // Does nothing at all
#endif