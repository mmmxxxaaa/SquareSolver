#include "logic_functions.h"

#include <stdbool.h>
#include <math.h>

bool is_zero(float number)
{
    const float epsilon = 1e-7f;
    return fabsf(number) < epsilon;
}
