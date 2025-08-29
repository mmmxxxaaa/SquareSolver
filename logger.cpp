#include "logger.h"

#include <stdio.h>
#include <stdarg.h>

static FILE* log_file = NULL;   //ДЕЛО СДЕЛАНО больше не таскаю logger_type во все функции
static enum LoggerPriority set_priority = LOGGER_PRIORITY_NOTHING;


void logger_output(enum LoggerPriority message_priority, const char *format, ...) //ДЕЛО СДЕЛАНО vfprintf
{
    va_list args;
    va_start(args, format);

    if (message_priority >= set_priority)
        vfprintf(log_file, format, args);
}

FILE* logger_init()
{
    log_file = fopen("logger.txt", "a");
    return log_file;
}

void logger_finish()
{
    fclose(log_file);
}

void logger_set_priority(enum LoggerPriority inputed_priority)
{
    set_priority = inputed_priority;
}
