#ifndef PROCESSING_H_
#define PROCESSING_H_

#include <stdbool.h>

#include "equation_solver.h"

bool get_coeffs(struct QuadricCoeffs* coeffs);
void output_general(struct AnswerAndSolution result);

void clear_input_stream(void);
int continue_request();

#endif // PROCESSING_H_
