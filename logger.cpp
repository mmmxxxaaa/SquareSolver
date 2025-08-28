#include "logger.h"

int logger_output(char* show_message, enum LoggerPriority message_priority,
                  enum LoggerPriority set_priority)
{
    if (message_priority >= set_priority)
        printf("%s", show_message);        //FIXME придумать что-нибудь с __func__
                                           //FIXME сделать вывод этих сообщений в файл
}
