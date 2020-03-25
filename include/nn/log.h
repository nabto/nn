#ifndef _NN_LOG_H_
#define _NN_LOG_H_

#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

enum nn_log_severity {
    NN_LOG_SEVERITY_ERROR,
    NN_LOG_SEVERITY_WARN,
    NN_LOG_SEVERITY_INFO,
    NN_LOG_SEVERITY_TRACE
};

typedef void (*nn_log_print)(enum nn_log_severity severity, const char* module, const char* file, int line, const char* fmt, va_list args);

struct nn_log {
    nn_log_print logFunction;
};

void nn_log_adapter(struct nn_log* logger, enum nn_log_severity severity, const char* module, const char* file, int line, const char* fmt, ...);

#define VA_ARGS(...) , ##__VA_ARGS__

#define NN_LOG_ERROR(logger, module, fmt, ...) do { nn_log_adapter(logger, NN_LOG_SEVERITY_ERROR, module, __FILE__, __LINE__, fmt VA_ARGS(__VA_ARGS__)); } while (0)

#define NN_LOG_WARN(logger, module, fmt, ...) do { nn_log_adapter(logger, NN_LOG_SEVERITY_WARN, module, __FILE__, __LINE__, fmt VA_ARGS(__VA_ARGS__)); } while (0)

#define NN_LOG_INFO(logger, module, fmt, ...) do { nn_log_adapter(logger, NN_LOG_SEVERITY_INFO, module, __FILE__, __LINE__, fmt VA_ARGS(__VA_ARGS__)); } while (0)

#define NN_LOG_TRACE(logger, module, fmt, ...) do { nn_log_adapter(logger, NN_LOG_SEVERITY_TRACE, module, __FILE__, __LINE__, fmt VA_ARGS(__VA_ARGS__)); } while (0)

#ifdef __cplusplus
} //extern "C"
#endif

#endif
