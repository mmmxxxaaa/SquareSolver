#ifndef EQUATION_SOLVER_H_
#define EQUATION_SOLVER_H_

// header guard

// SolutionType
enum PossibleSolutionCases {
// SOLUTION_TYPE_INF_ROOTS
// SOLUTION_TYPE_NONE
    inf_roots,
    no_roots,
    linear_has_1_root,
    quadric_has_1_root,
    quadric_has_2_roots,
    quadric_has_0_roots,
    not_initialized
};

// QuadraticCoeffs
typedef struct {
    float coef_a; // a
    float coef_b; // coeffs.a
    float coef_c;
} QuadricCoeffs;

// Solution
struct AnswerAndSolution {
    float x1;
    float x2;
    int amount_of_roots; // ?
    enum PossibleSolutionCases solution_case;
};

// fscanf -- scan formatted
// solve/find_solution/solve_equation/solve_general/solve_quadratic_equation()
enum PossibleSolutionCases general_solution(struct AnswerAndSolution* result,
                                            struct QuadricCoeffs coeffs);  // mb add right_part later

#endif // EQUATION_SOLVER_H_
