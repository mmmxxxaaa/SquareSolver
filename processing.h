#ifndef PROCESSING_H_
#define PROCESSING_H_

#include <stdbool.h>

#include "equation_solver.h"
#include "colors_codes.h"

bool get_coeffs(struct QuadricCoeffs* coeffs);
void general_output(struct AnswerAndSolution result);

void clear_input_stream(void);
int continue_request();

#endif // PROCESSING_H_
