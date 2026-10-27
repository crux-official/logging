#ifndef CRUX_DYNAMIC_LOGGING_H
#define CRUX_DYNAMIC_LOGGING_H

#include "kernel_types.h"
#include "logging_api.h"
#include "engine.h"
#include "kernel_types.h"

#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

// The dynamic rendering of the logging contract: every call dispatches through
// the engine's registry channel - the logging driver's served LoggingAPI,
// selected by the concern's stable dispatch id (DRIVER_LOGGING,
// platform_types.h). The plain-variadic forms pack the caller's args and
// dispatch the va_list forms.
#define LOGGING_API ((LoggingAPI *)crux_engine_api->GetExtensionAPI(DRIVER_LOGGING))
static inline void Log(const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  LOGGING_API->LogV(fmt, args);
  va_end(args);
}
static inline void LogWarning(const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  LOGGING_API->LogWarningV(fmt, args);
  va_end(args);
}
static inline void LogError(const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  LOGGING_API->LogErrorV(fmt, args);
  va_end(args);
}
static inline void LogV(const char *fmt, va_list args) { LOGGING_API->LogV(fmt, args); }
static inline void LogWarningV(const char *fmt, va_list args) { LOGGING_API->LogWarningV(fmt, args); }
static inline void LogErrorV(const char *fmt, va_list args) { LOGGING_API->LogErrorV(fmt, args); }
#undef LOGGING_API

#ifdef __cplusplus
}
#endif

#endif
