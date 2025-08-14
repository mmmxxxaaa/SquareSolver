#ifndef FUNCTIONS_HEADER
#define FUNCTIONS_HEADER

#include <stdbool.h>


enum possible_solution_cases {all_abc_coef_0,
                              only_ab_coef_0,
                              only_a_coef_0,
                              quadric_has_1_root,
                              quadric_has_2_roots,
                              quadric_has_0_roots};

bool get_coeffs(float *ptr_a, float *ptr_b, float *ptr_c);
float make_discriminant(float coeff_a, float coeff_b, float coeff_c);
void make_roots(float *ptr_x1, float *ptr_x2, float coeff_a, float coeff_b, float discriminant);
void search_right_part(float * ptr_right_part);  //Not necessary function yet

enum possible_solution_cases solve_normal_linear_equation(float * ptr_x1, float * ptr_x2, int * ptr_amount_of_roots, float coeff_b, float coeff_c);
enum possible_solution_cases solve_normal_quadratic_equation(float * ptr_x1, float * ptr_x2, int * ptr_amount_of_roots, float coeff_a, float coeff_b, float coeff_c);

enum possible_solution_cases general_solution(float * ptr_x1, float * ptr_x2, int * ptr_amount_of_roots, float coeff_a, float coeff_b, float coeff_c);  // mb add right_part later
void general_output(float x1, float x2, int amount_of_roots, enum possible_solution_cases solution_case);

bool is_zero(float number);
void clear_input_stream(void);
int continue_request();

#endif
