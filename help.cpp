#include "help.h"

#include <stdio.h>
#include <stdlib.h>

void help(const char* parameter)
{
    system("ncal");

    printf("parameter %s\n", parameter); //ДЕЛО СДЕЛАНО вызывать ncal внутри help (календарь)
    printf("--interactive  Sets interactive mode");
    printf("Enter new quadratic quadratic equation coefficients"
        " in the following format: \"a b c\", where ax^2 + bx + c = 0 \n");
    printf("--test         Sets the test mode");
    printf("You should not enter anything. The information about passed tests will be shown you");
    printf ("\n");
}
