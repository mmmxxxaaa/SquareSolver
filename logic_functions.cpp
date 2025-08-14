#include <stdbool.h>
#include <math.h>

#include "logic_functions.h"

bool is_zero(float number)
{
    const double epsilon = 1e-7;
    return fabs(number) < epsilon;
}
