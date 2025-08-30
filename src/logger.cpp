#include "../include/logger.h"

#include <stdio.h>
#include <stdarg.h>

#include "../include/colors_codes.h"

static FILE* log_file = NULL;
static enum LoggerPriority set_priority = LOGGER_PRIORITY_ERROR;


void logger_output(enum LoggerPriority message_priority, const char *format, ...)
{
    if (message_priority < set_priority)
        return;

    va_list args = {};
    va_start(args, format);

    vfprintf(log_file, format, args);
    va_end(args);
}

void logger_init()
{
    log_file = fopen("./logger/logger.txt", "a");
    if (log_file == NULL)
    {
        printf(RED "Cannot open the \"logger.txt\" file" RESET);
    }
}

void logger_finish()
{
    fclose(log_file);
}

void logger_set_priority(enum LoggerPriority inputed_priority)
{
    set_priority = inputed_priority;
}
