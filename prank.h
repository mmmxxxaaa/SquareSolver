#ifndef PRANK_H_
#define PRANK_H_

#include "logger.h"

/**
    @brief Запускает шуточную работу программы
**/
void prank(enum LoggerPriority logger_type);

/**
    @brief Необходима для работы шуточной версии программы
**/
void processing_prank(enum LoggerPriority logger_type);

void poltoraIIIka(const char *message);

#endif
