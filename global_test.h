#ifndef GLOBAL_TEST_H_
#define GLOBAL_TEST_H_

#include "equation_solver.h"
#include "logger.h"

/**
    @brief Структура хранит в себе данные для тестов:
        структура коэффициентов,
        структура ожидаемых результатов

*/
typedef struct {
    QuadricCoeffs tests_coeffs;
    RootsAndCase tests_results;
} Test;


/**
    @brief Функция запускает тесты всех функций
*/
void global_test();


/**
    @brief Функция запускает тесты equation_solver из файла
*/
int run_tests_from_file(int* success_tests, int* all_tests);

#endif // GLOBAL_TEST_H_
