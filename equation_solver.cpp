#include "equation_solver.h"

#include <math.h>
#include <stdio.h>
#include <assert.h>

#include "processing.h"
#include "logic_functions.h"

static float make_discriminant(struct QuadricCoeffs coeffs);
static void make_roots(float *ptr_x1, float *ptr_x2, float coeff_a, float coeff_b, float discriminant);

static enum PossibleSolutionCases solve_normal_linear_equation(float * ptr_x1, float * ptr_x2, int * ptr_amount_of_roots, float coeff_b, float coeff_c);
static enum PossibleSolutionCases solve_normal_quadratic_equation(float * ptr_x1, float * ptr_x2, int * ptr_amount_of_roots, struct QuadricCoeffs coeffs);

static float make_discriminant(struct QuadricCoeffs coeffs)
{
    return coeffs.coef_b * coeffs.coef_b - 4 * coeffs.coef_a * coeffs.coef_c;
}

static void make_roots(float *ptr_x1, float *ptr_x2, float coef_a, float coef_b, float discriminant)
{
    assert(ptr_x1 != NULL);
    assert(ptr_x2 != NULL);

    float discr_square_root = sqrtf(discriminant);

    float root_1 = ((-1) * coef_b + discr_square_root) / (2 * coef_a);
    float root_2 = ((-1) * coef_b - discr_square_root) / (2 * coef_a);
    if (is_zero(root_1))
        *ptr_x1 = 0.0f;
    else
        *ptr_x1 = root_1;
    if (is_zero(root_2))
        *ptr_x2 = 0.0f;
    else
        *ptr_x2 = root_2;
}

static enum PossibleSolutionCases solve_normal_linear_equation(float * ptr_x1, float * ptr_x2, int * ptr_amount_of_roots, float coef_b, float coef_c)
{
    assert(ptr_x1 != NULL);
    assert(ptr_x2 != NULL);
    assert(ptr_amount_of_roots != NULL);

    float root = -coef_c/coef_b;
    if (is_zero(root))
        *ptr_x1 = *ptr_x2 = 0.0f; //avoiding -0.0 case
    else
        *ptr_x1 = *ptr_x2 = -coef_c/coef_b;
    *ptr_amount_of_roots = 1;

    return linear_has_1_root;
}

static enum PossibleSolutionCases solve_normal_quadratic_equation(float * ptr_x1, float * ptr_x2, int * ptr_amount_of_roots, struct QuadricCoeffs coeffs)
{
    assert(ptr_x1 != NULL);
    assert(ptr_x2 != NULL);
    assert(ptr_amount_of_roots != NULL);

    float discriminant = make_discriminant(coeffs);

    if (discriminant < 0)
    {
        *ptr_amount_of_roots = 0;

        return quadric_has_0_roots;
    }
    else if (is_zero(discriminant))
    {
        make_roots(ptr_x1, ptr_x2, coeffs.coef_a, coeffs.coef_b, fabs(discriminant));
        *ptr_amount_of_roots = 1;

        return quadric_has_1_root;
    }
    else
    {
        make_roots(ptr_x1, ptr_x2, coeffs.coef_a, coeffs.coef_b, discriminant);
        *ptr_amount_of_roots = 2;

        return quadric_has_2_roots;
    }
}

enum PossibleSolutionCases general_solution(struct AnswerAndSolution * result, struct QuadricCoeffs coeffs)
{
    assert(result != NULL);

    if (is_zero(coeffs.coef_a) && is_zero(coeffs.coef_b) && is_zero(coeffs.coef_c))
        return inf_roots;
    else if (is_zero(coeffs.coef_a) && is_zero(coeffs.coef_b))
        return no_roots;
    else if (is_zero(coeffs.coef_a))
        return solve_normal_linear_equation(&(result->x1), &(result->x2), &(result->amount_of_roots), coeffs.coef_b, coeffs.coef_c);
    else
        return solve_normal_quadratic_equation(&(result->x1), &(result->x2), &(result->amount_of_roots), coeffs);
}
