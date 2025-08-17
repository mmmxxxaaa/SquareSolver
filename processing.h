#ifndef PROCESSING_H_
#define PROCESSING_H_

#include <stdbool.h>
#include "equation_solver.h"

struct quadric_coeffs{
            float coef_a;
            float coef_b;
            float coef_c;
        };

bool get_coeffs(struct quadric_coeffs * coeffs);
void search_right_part(float * ptr_right_part);  //Not necessary function yet
void general_output(float x1, float x2, int amount_of_roots, enum possible_solution_cases solution_case);

void clear_input_stream(void);
int continue_request();

#endif // PROCESSING_H_
