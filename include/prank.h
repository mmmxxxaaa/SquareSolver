#ifndef PRANK_H_
#define PRANK_H_

#include "logger.h"

/**
    @brief Запускает шуточную работу программы
**/
void prank();

/**
    @brief Необходима для работы шуточной версии программы
**/
void processing_prank();

/**
    @brief Функция выводит полосу загрузки
**/
void loading_bar_imitation();

/**
    @brief Функция выводит картинку кошки Полторашки, которая что-то говорит :-)

    @param[in] message - указатель на строку, которую произносит Полторашка
**/
void poltoraIIIka(const char *message);

#endif
