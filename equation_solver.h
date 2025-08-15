#ifndef EQUATION_SOLVER_H_
#define EQUATION_SOLVER_H_

enum possible_solution_cases {
    inf_roots,
    no_roots,
    linear_has_1_root,
    quadric_has_1_root,
    quadric_has_2_roots,
    quadric_has_0_roots
};

enum possible_solution_cases general_solution(float * ptr_x1, float * ptr_x2, int * ptr_amount_of_roots, float coeff_a, float coeff_b, float coeff_c);  // mb add right_part later

#endif // EQUATION_SOLVER_H_
