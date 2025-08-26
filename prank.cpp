#include "prank.h"

#include <stdio.h>

#include "colors_codes.h"
#include "io.h"
#include "equation_solver.h"
#include "time.h"

void prank()
{
    puts(BLUE "Enter new quadratic quadratic equation coefficients"
        " in the following format: \"a b c\", where ax^2 + bx + c = 0" RESET);
    for (int i = 0; i < 10; i++)
    {
        QuadricCoeffs coeffs = {0};

        bool got_success = get_coeffs(&coeffs);
        clear_input_stream();

        if (got_success)
        {
            processing_prank();
            break;
        }
        if (continue_request() == -1)
            break;
    }
}

void processing_prank()
{
    printf("Are you sure that the a coefficient is 0?\n");
    //scanf("%256s", &answer);
    clear_input_stream();
    printf("OK :-) \n");
    printf("starting thinking\n");
    time_t start_time, end_time; //TODO сделать вращающийся кружочку
    time(&start_time);
    while ((time(&end_time) - start_time) < 5)
        ;

    time(&start_time);
    while (time(&end_time) - start_time < 2)
    {
        printf("thinking\n");
    }
    time(&start_time);
    printf("Oh, this task is really hard\n");
    while (time(&end_time) - start_time < 4)
        ;

    time(&start_time);
    while (time(&end_time) - start_time < 2)
        printf("thinking\n");

    printf("The answer is POGLYAD POLTORASHKY\n");
    poltoraIIIka("MEOW");
}

void poltoraIIIka(const char *name) {
    printf(" ");
    printf(" \n");
    printf("       ....／＞　 フ.....\n"
    "　　　　　| 　_　 _|\n"
    "　 　　　／`ミ _* 彡 -- %s!!\n"
    "　　 　 /　　　 　 |\n"
    "　　　 /　 ヽ　　 ﾉ\n"
    "　／￣|　　 |　|　|\n"
    "　| (￣ヽ＿_ヽ_)_)\n"
    "　＼二つ\n", name);
    printf(" \n");
    printf(" ");
}


//ДЕЛО СДЕЛАНО
