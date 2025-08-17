#include <math.h>
#include <stdio.h>
#include <assert.h>

#include "equation_solver.h"
#include "processing.h"
#include "logic_functions.h"

static float make_discriminant(float coeff_a, float coeff_b, float coeff_c);
static void make_roots(float *ptr_x1, float *ptr_x2, float coeff_a, float coeff_b, float discriminant);

static enum possible_solution_cases solve_normal_linear_equation(float * ptr_x1, float * ptr_x2, int * ptr_amount_of_roots, float coeff_b, float coeff_c);
static enum possible_solution_cases solve_normal_quadratic_equation(float * ptr_x1, float * ptr_x2, int * ptr_amount_of_roots, struct quadric_coeffs coeffs);

static float make_discriminant(float coef_a, float coef_b, float coef_c)
{
    return coef_b * coef_b - 4 * coef_a * coef_c;
}

static void make_roots(float *ptr_x1, float *ptr_x2, float coef_a, float coef_b, float discriminant)
{
    assert(ptr_x1 != NULL);
    assert(ptr_x2 != NULL);

    float discr_square_root = sqrtf(discriminant);

    *ptr_x1 = ((-1) * coef_b + discr_square_root) / (2 * coef_a);
    *ptr_x2 = ((-1) * coef_b - discr_square_root) / (2 * coef_a);
}

static enum possible_solution_cases solve_normal_linear_equation(float * ptr_x1, float * ptr_x2, int * ptr_amount_of_roots, float coef_b, float coef_c)
{
    assert(ptr_x1 != NULL);
    assert(ptr_x2 != NULL);
    assert(ptr_amount_of_roots != NULL);

    *ptr_x1 = *ptr_x2 = -coef_c/coef_b;
    *ptr_amount_of_roots = 1;

    return linear_has_1_root;
}

static enum possible_solution_cases solve_normal_quadratic_equation(float * ptr_x1, float * ptr_x2, int * ptr_amount_of_roots, struct quadric_coeffs coeffs)
{
    assert(ptr_x1 != NULL);
    assert(ptr_x2 != NULL);
    assert(ptr_amount_of_roots != NULL);

    float discriminant = make_discriminant(coeffs.coef_a, coeffs.coef_b, coeffs.coef_c);

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

enum possible_solution_cases general_solution(struct answer_and_solution * result, struct quadric_coeffs coeffs)
{
    assert(result != NULL);
    assert(&(result -> x1) != NULL);
    assert(&(result -> x2) != NULL);
    assert(&(result -> amount_of_roots) != NULL);

    if (is_zero(coeffs.coef_a) && is_zero(coeffs.coef_b) && is_zero(coeffs.coef_c))
        return inf_roots;
    else if (is_zero(coeffs.coef_a) && is_zero(coeffs.coef_b))
        return no_roots;
    else if (is_zero(coeffs.coef_a))
        return solve_normal_linear_equation(&(result -> x1), &(result -> x2), &(result -> amount_of_roots), coeffs.coef_b, coeffs.coef_c);
    else
        return solve_normal_quadratic_equation(&(result -> x1), &(result -> x2), &(result -> amount_of_roots), coeffs);
}
