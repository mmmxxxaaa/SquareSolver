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

struct QuadricCoeffs {
    float a;
    float b;
    float c;
};

struct AnswerAndSolution {
    float x1;
    float x2;
    enum SolutionType solution_case;
};

enum SolutionType general_solution(struct AnswerAndSolution* result, struct QuadricCoeffs coeffs);  // mb add right_part later

#endif // EQUATION_SOLVER_H_
