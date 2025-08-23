#ifndef EQUATION_SOLVER_TEST_H_
#define EQUATION_SOLVER_TEST_H_

#include "equation_solver.h"


void make_coeffs(float coef_a, float coef_b, float coef_c, QuadricCoeffs* ptr_coeffs);
void test_normal_solve_general(QuadricCoeffs* ptr_coeffs, AnswerAndSolution* ptr_result, float expecting_x1, float expecting_x2, enum SolutionType expecting_case);
void test_solve_general_simplified(float coef_a, float coef_b, float coef_c, float expecting_x1, float expecting_x2, enum SolutionType expecting_case);

#endif // EQUATION_SOLVER_TEST_H_
