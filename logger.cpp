#include "logger.h"

#include <stdio.h>

static FILE* log_file = NULL;   //ДЕЛО СДЕЛАНО
static enum LoggerPriority set_priority = LOGGER_PRIORITY_NOTHING;


void logger_output(const char* show_message, enum LoggerPriority message_priority) //vfprintf
{
    if (message_priority >= set_priority)
        fprintf(log_file, "%s", show_message);
}

FILE* logger_init()
{
    log_file = fopen("logger.txt", "a");
    return log_file;
}

void logger_finish(FILE* file)
{
    fclose(file);
}

void logger_set_priority(enum LoggerPriority inputed_priority)
{
    set_priority = inputed_priority;
}
