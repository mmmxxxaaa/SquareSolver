#ifndef MY_LOGGER_H_
#define MY_LOGGER_H_

#include <stdio.h>
#include "errors_codes.h"

enum LoggerPriority {
    LOGGER_PRIORITY_DEBUG,
    LOGGER_PRIORITY_INFO,
    LOGGER_PRIORITY_WARNING,
    LOGGER_PRIORITY_ERROR,
    LOGGER_PRIORITY_CRITICAL,
    LOGGER_PRIORITY_NOTHING
};

/**
*   @brief Функция сравнивает приоритет сообщения с выставленным при запуске приоритетом логгера
*          и выводит его, если он выше или равен выставленному приоритету
*
*   @param[in] message_priority - приоритет выводимого сообщения
*   @param[in] format - указатель на строку с форматами
*   @param[in] ... - аргументы для подстановки в строку с форматами
**/
void logger_output(enum LoggerPriority message_priority, const char* format, ...);

/**
*   @brief Функция открывает файл для записи логгеров
**/
enum ErrorsCodes logger_init(const char* filename);

/**
*   @brief Функция закрывает файл для записи логгеров
**/
enum ErrorsCodes logger_finish();

/**
*   @brief Функция устанавливает введённый пользователем приоритет логгеров
*
*   @param[in] inputed_priority - введённый пользователем при запуске программы приоритет логгеров
**/
void logger_set_priority(enum LoggerPriority inputed_priority);


#endif // MY_LOGGER_H_
