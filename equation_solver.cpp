#include "equation_solver.h"

#include <math.h>
#include <stdio.h>
#include <assert.h>

#include "logic_functions.h"

static float make_discriminant(struct QuadricCoeffs coeffs);
static void make_roots(float* ptr_x1, float* ptr_x2, struct QuadricCoeffs coeffs, float discriminant);

static enum PossibleSolutionCases solve_normal_linear_equation(float* ptr_x1, float* ptr_x2, int* ptr_amount_of_roots, struct QuadricCoeffs coeffs);
static enum PossibleSolutionCases solve_normal_quadratic_equation(float* ptr_x1, float* ptr_x2, int* ptr_amount_of_roots, struct QuadricCoeffs coeffs);

enum PossibleSolutionCases general_solution(struct AnswerAndSolution * result, struct QuadricCoeffs coeffs)
{
    assert(result != NULL);
    assert(is_finite(coeffs.coef_a));
    assert(is_finite(coeffs.coef_b));
    assert(is_finite(coeffs.coef_c));

    if (is_zero(coeffs.coef_a) && is_zero(coeffs.coef_b) && is_zero(coeffs.coef_c))
        return inf_roots;
    else if (is_zero(coeffs.coef_a) && is_zero(coeffs.coef_b))
        return no_roots;
    else if (is_zero(coeffs.coef_a))
        return solve_normal_linear_equation(&(result->x1), &(result->x2), &(result->amount_of_roots), coeffs);
    else
        return solve_normal_quadratic_equation(&(result->x1), &(result->x2), &(result->amount_of_roots), coeffs);
}

static float make_discriminant(struct QuadricCoeffs coeffs)
{
    return coeffs.coef_b * coeffs.coef_b - 4 * coeffs.coef_a * coeffs.coef_c;
}

static void make_roots(float *ptr_x1, float *ptr_x2, struct QuadricCoeffs coeffs, float discriminant)
{
    assert(ptr_x1 != NULL);
    assert(ptr_x2 != NULL);
    assert(is_finite(coeffs.coef_a));
    assert(is_finite(coeffs.coef_b));

    float discr_square_root = sqrtf(discriminant);

    float root_1 = ((-1) * coeffs.coef_b + discr_square_root) / (2 * coeffs.coef_a);
    float root_2 = ((-1) * coeffs.coef_b - discr_square_root) / (2 * coeffs.coef_a);

    *ptr_x1 = is_zero(root_1) ? 0.0f : root_1;
    *ptr_x2 = is_zero(root_2) ? 0.0f : root_2;
}

static enum PossibleSolutionCases solve_normal_linear_equation(float* ptr_x1, float* ptr_x2, int* ptr_amount_of_roots, struct QuadricCoeffs coeffs)
{
    assert(ptr_x1 != NULL);
    assert(ptr_x2 != NULL);
    assert(ptr_amount_of_roots != NULL);
    assert(is_finite(coeffs.coef_b));
    assert(is_finite(coeffs.coef_c));

    float root = -coeffs.coef_c/coeffs.coef_b;
    *ptr_x1 = is_zero(root) ? 0.0f : root;  //avoiding -0.0 case
    *ptr_x2 = *ptr_x1;
    *ptr_amount_of_roots = 1;

    return linear_has_1_root;
}

static enum PossibleSolutionCases solve_normal_quadratic_equation(float * ptr_x1, float * ptr_x2, int * ptr_amount_of_roots, struct QuadricCoeffs coeffs)
{
    assert(ptr_x1 != NULL);
    assert(ptr_x2 != NULL);
    assert(ptr_amount_of_roots != NULL);
    assert(is_finite(coeffs.coef_a));
    assert(is_finite(coeffs.coef_b));
    assert(is_finite(coeffs.coef_c));

    float discriminant = make_discriminant(coeffs);

    if (discriminant < 0)
    {
        *ptr_amount_of_roots = 0;

        return quadric_has_0_roots;
    }
    else if (is_zero(discriminant))
    {
        make_roots(ptr_x1, ptr_x2, coeffs, fabs(discriminant));
        *ptr_amount_of_roots = 1;

        return quadric_has_1_root;
    }
    else
    {
        make_roots(ptr_x1, ptr_x2, coeffs, discriminant);
        *ptr_amount_of_roots = 2;

        return quadric_has_2_roots;
    }
}

