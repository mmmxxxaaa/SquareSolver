#include "prank.h"

#include <stdio.h>

#include "colors_codes.h"
#include "io.h"
#include "equation_solver.h"
#include "time.h"
#include "my_assert.h"
#include "logger.h"

const int thinking_time_long = 4;
const int thinking_time_short = 2;

static void thinking_silent(time_t thinking_time);
static void thinking_shout(time_t thinking_time);

void prank()
{
    const int prank_number = 10;

    puts(BLUE "Enter new quadratic quadratic equation coefficients"
        " in the following format: \"a b c\", where ax^2 + bx + c = 0" RESET);
    for (int i = 0; i < prank_number; i++)
    {
        QuadricCoeffs coeffs = {0};

        bool got_success = get_coeffs(&coeffs);
        clear_input_stream();

        if (got_success)
        {
            logger_output("prank(): starting processing_prank()\n", LOGGER_PRIORITY_INFO);
            processing_prank();
            break;

        }
        if (continue_request() == -1)
        {
            logger_output("prank(): wrong input coefficients\n", LOGGER_PRIORITY_ERROR);
            break;
        }
    }
}

void processing_prank()
{
    printf("Are you sure that the a coefficient is 0?\n");
    clear_input_stream();
    printf("OK :-) \n");
    printf("starting thinking\n");

    thinking_silent(thinking_time_long);

    thinking_shout(thinking_time_short);

    printf("Oh, this task is really hard\n");

    thinking_silent(thinking_time_long);

    thinking_shout(thinking_time_short);

    printf("The answer is POGLYAD POLTORASHKY\n");
    poltoraIIIka("MEOW");
    logger_output("printed poltoraIIIka result\n", LOGGER_PRIORITY_INFO);
}

void poltoraIIIka(const char *name)
{
    MY_ASSERT(name != NULL);

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

void thinking_silent(time_t thinking_time)
{
    time_t start_time, end_time;
    time(&start_time);
    while ((time(&end_time) - start_time) < thinking_time)
        ;
}

void thinking_shout(time_t thinking_time)
{
    time_t start_time, end_time;
    time(&start_time);
    while ((time(&end_time) - start_time) < thinking_time)
        printf("thinking\n");
}
