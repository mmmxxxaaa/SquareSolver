#include "logger.h"

#include <stdio.h>

void logger_output(const char* show_message, enum LoggerPriority message_priority,
                  enum LoggerPriority set_priority) //vfprintf
{
    FILE *file = fopen("logger.txt", "a");

    if (message_priority >= set_priority)
        fprintf(file, "%s", show_message);        //FIXME придумать что-нибудь с __func__
                                           //FIXME сделать вывод этих сообщений в файл

    fclose(file);
}
