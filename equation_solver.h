#ifndef EQUATION_SOLVER_H_
#define EQUATION_SOLVER_H_

enum PossibleSolutionCases {
    inf_roots,
    no_roots,
    linear_has_1_root,
    quadric_has_1_root,
    quadric_has_2_roots,
    quadric_has_0_roots,
    not_initialized
};

struct QuadricCoeffs {
    float coef_a;
    float coef_b;
    float coef_c;
};

struct AnswerAndSolution {
    float x1;
    float x2;
    int amount_of_roots;
    enum PossibleSolutionCases solution_case;
};

enum PossibleSolutionCases general_solution(struct AnswerAndSolution* result, struct QuadricCoeffs coeffs);  // mb add right_part later

#endif // EQUATION_SOLVER_H_
