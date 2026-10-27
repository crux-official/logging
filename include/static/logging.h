#ifndef CRUX_STATIC_LOGGING_H
#define CRUX_STATIC_LOGGING_H

#include "kernel_types.h"
#include "logging_api.h"

#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

// The static rendering of the logging contract: plain externs, defined by the
// logging driver and linked into the binary. The plain-variadic forms are
// the ergonomic call sites; the va_list forms are the contract (the driver
// defines both).
extern void Log(const char *fmt, ...);
extern void LogWarning(const char *fmt, ...);
extern void LogError(const char *fmt, ...);
extern void LogV(const char *fmt, va_list args);
extern void LogWarningV(const char *fmt, va_list args);
extern void LogErrorV(const char *fmt, va_list args);

#ifdef __cplusplus
}
#endif

#endif
