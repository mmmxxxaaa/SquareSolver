#ifndef EQUATION_SOLVER_H_
#define EQUATION_SOLVER_H_

enum SolutionType {
    SOLUTION_TYPE_INF_ROOTS,
    SOLUTION_TYPE_NO_ROOTS,
    SOLUTION_TYPE_LINEAR_HAS_1_ROOT,
    SOLUTION_TYPE_QUADRATIC_HAS_1_ROOT,
    SOLUTION_TYPE_QUADRATIC_HAS_2_ROOTS,
    SOLUTION_TYPE_QUADRATIC_HAS_0_ROOTS,
    SOLUTION_TYPE_NONE
};

typedef struct {
    float a;
    float b;
    float c;
} QuadricCoeffs;

typedef struct {
    float x1;
    float x2;
    enum SolutionType solution_case;
} AnswerAndSolution;

enum SolutionType solve_general(const QuadricCoeffs* ptr_coeffs, AnswerAndSolution* ptr_result);  // mb add right_part later

#endif // EQUATION_SOLVER_H_
