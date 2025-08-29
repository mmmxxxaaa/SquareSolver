#ifndef MY_LOGGER_H_
#define MY_LOGGER_H_

#include <stdio.h>

enum LoggerPriority {
    LOGGER_PRIORITY_DEBUG,
    LOGGER_PRIORITY_INFO,
    LOGGER_PRIORITY_WARNING,
    LOGGER_PRIORITY_ERROR,
    LOGGER_PRIORITY_CRITICAL,
    LOGGER_PRIORITY_NOTHING
};

void logger_output(const char* show_message, enum LoggerPriority message_priority);
FILE* logger_init();
void logger_finish(FILE* file);
void logger_set_priority(enum LoggerPriority inputed_priority);


#endif // MY_LOGGER_H_
