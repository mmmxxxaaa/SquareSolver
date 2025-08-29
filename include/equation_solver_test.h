#ifndef EQUATION_SOLVER_TEST_H_
#define EQUATION_SOLVER_TEST_H_

#include "equation_solver.h"

/**
    @brief Эта функция тестирует результаты функции solve_general
    @param[in] coeffs - структура с коэффициентами квадратного уравнения
    @param[in] expected_result - структура с ожидаемыми результатами теста

    @return 1, если тест прошёл успешно, и 0, если тест не прошёл
*/
int test_solve_general(QuadricCoeffs coeffs, RootsAndCase expected_result);

#endif // EQUATION_SOLVER_TEST_H_
