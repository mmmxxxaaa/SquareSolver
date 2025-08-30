#include "logger.h"

#include <stdio.h>
#include <stdarg.h>

#include "colors_codes.h"
#include "errors_codes.h"

static FILE* log_file = NULL;
static enum LoggerPriority global_priority = LOGGER_PRIORITY_ERROR;


void logger_output(enum LoggerPriority message_priority, const char *format, ...)
{
    if (message_priority < global_priority)
        return;

    va_list args = {};
    va_start(args, format);

    vfprintf(log_file, format, args);
    va_end(args);
}


//FIXME и начать писать строковые функции (свои вместо стандартных)
enum ErrorsCodes logger_init(const char* filename) // ДЕЛО СДЕЛАНО принимать имя файла
{
    log_file = fopen(filename, "a");

    if (log_file == NULL)
        return ERROR_OPENING_FILE;
    return NO_ERROR;
}

enum ErrorsCodes logger_finish()
{
    if (log_file == NULL)
        return ERROR_CLOSING_FILE;

    fclose(log_file);
    return NO_ERROR;
}

void logger_set_priority(enum LoggerPriority inputed_priority)
{
    global_priority = inputed_priority;
}
