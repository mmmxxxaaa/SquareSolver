#ifndef GLOBAL_TEST_H_
#define GLOBAL_TEST_H_

#include "equation_solver.h"

typedef struct {
    QuadricCoeffs tests_coeffs;
    RootsAndCase tests_results;
} Test;

void global_test();

#endif // GLOBAL_TEST_H_
