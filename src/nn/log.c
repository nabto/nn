#include <nn/log.h>

void nn_log_adapter(struct nn_log* logger, enum nn_log_severity severity, const char* module, const char* file, int line, const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    logger->logFunction(severity, module, file, line, fmt, args);
    va_end(args);
}
