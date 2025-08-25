#include "help.h"

#include <stdio.h>
#include <stdlib.h>

void help(const char* parameter)
{
    system("ncal");

    printf ("parameter %s\n", parameter); //ДЕЛО СДЕЛАНО вызывать ncal внутри help (календарь)
    printf("Enter new quadratic quadratic equation coefficients"
        " in the following format: \"a b c\", where ax^2 + bx + c = 0 \n");
    printf ("\n");
}
