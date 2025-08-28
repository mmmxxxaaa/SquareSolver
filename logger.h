#ifndef MY_LOGGER_H_
#define MY_LOGGER_H_

enum LoggerPriority {
    LOGGER_PRIORITY_DEBUG,
    LOGGER_PRIORITY_INFO,
    LOGGER_PRIORITY_WARNING,
    LOGGER_PRIORITY_ERROR,
    LOGGER_PRIORITY_CRITICAL,
    LOGGER_PRIORITY_NOTHING
};

int logger_output(char* show_message, enum LoggerPriority priority);

#endif // MY_LOGGER_H_
