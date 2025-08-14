#ifndef PROCESSING_H_
#define PROCESSING_H_

#include <stdbool.h>
#include "equation_solver.h"


bool get_coeffs(float *ptr_a, float *ptr_b, float *ptr_c);
void search_right_part(float * ptr_right_part);  //Not necessary function yet
void general_output(float x1, float x2, int amount_of_roots, enum possible_solution_cases solution_case);

void clear_input_stream(void);
int continue_request();

#endif // PROCESSING_H_
