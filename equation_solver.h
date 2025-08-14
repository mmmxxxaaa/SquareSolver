#ifndef EQUATION_SOLVER_H_
#define EQUATION_SOLVER_H_

float make_discriminant(float coeff_a, float coeff_b, float coeff_c);
void make_roots(float *ptr_x1, float *ptr_x2, float coeff_a, float coeff_b, float discriminant);
void search_right_part(float * ptr_right_part);  //Not necessary function yet

enum possible_solution_cases solve_normal_linear_equation(float * ptr_x1, float * ptr_x2, int * ptr_amount_of_roots, float coeff_b, float coeff_c);
enum possible_solution_cases solve_normal_quadratic_equation(float * ptr_x1, float * ptr_x2, int * ptr_amount_of_roots, float coeff_a, float coeff_b, float coeff_c);

enum possible_solution_cases general_solution(float * ptr_x1, float * ptr_x2, int * ptr_amount_of_roots, float coeff_a, float coeff_b, float coeff_c);  // mb add right_part later

#endif //EQUATION_SOLVER_H_
