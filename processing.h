#ifndef PROCESSING_H_
#define PROCESSING_H_

#include <stdbool.h>

#include "equation_solver.h"

bool get_coeffs(struct quadric_coeffs * coeffs);
void general_output(struct answer_and_solution result);

void clear_input_stream(void);
int continue_request();

#endif // PROCESSING_H_
