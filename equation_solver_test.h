#ifndef EQUATION_SOLVER_TEST_H_
#define EQUATION_SOLVER_TEST_H_

#include "equation_solver.h"


void make_coeffs(float coef_a, float coef_b, float coef_c, QuadricCoeffs* ptr_coeffs);
void test_solve_general(QuadricCoeffs coeffs, AnswerAndSolution ideal_result);


#endif // EQUATION_SOLVER_TEST_H_
