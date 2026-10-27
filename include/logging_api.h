#ifndef CRUX_LOGGING_API_H
#define CRUX_LOGGING_API_H

#include "kernel_types.h"

#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

// The logging concern's contract: the one struct of function pointers the
// logging driver fills and serves - the log sink (the three severities, the
// va_list forms). A variadic signature cannot portably sit in a
// function-pointer struct, so the struct carries the va_list forms; the
// renderings' plain-variadic inlines pack the caller's args and dispatch
// these.
//
// The concern is dispatched through the engine's registry channel: the
// driver's served LoggingAPI, selected by the concern's stable dispatch id.
typedef struct LoggingAPI {
  PackageVersion version;
  void (*LogV)(const char *fmt, va_list args);
  void (*LogWarningV)(const char *fmt, va_list args);
  void (*LogErrorV)(const char *fmt, va_list args);
} LoggingAPI;

#ifdef __cplusplus
}
#endif

#endif
