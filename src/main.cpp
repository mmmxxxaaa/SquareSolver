#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

#include "io.h"
#include "equation_solver.h"
#include "colors_codes.h"
#include "errors_codes.h"
#include "my_static_assert.h"
#include "my_assert.h"

#include "global_test.h"
#include "interactive_mode.h"
#include "help.h"
#include "prank.h"
#include "logger.h"

typedef struct {
    bool help_requested;
    bool interactive_requested;
    bool test_requested;
    bool prank_requested;
} RequestedFlags;


enum LoggerPriority str_to_enum(char* ch);

int main(const int argc, char** argv)
{
    enum ErrorsCodes error_in_file = logger_init("./logger/logger.txt");
    MY_ASSERT(error_in_file == NO_ERROR);

    RequestedFlags requests = {false, false, false, false};

    int option_index = 0;
    static struct option long_options[] = {
        {"help",         0, 0, 'h'},
        {"interactive",  0, 0, 'i'},
        {"test",         0, 0, 't'},
        {"prank",        0, 0, 'p'},
        {"logger",       1, 0, 'l'},
        {0,              0, 0,  0}
    };

    int option_symbol = '\0';
    while ((option_symbol = getopt_long(argc, argv, "hitpl", long_options, &option_index)) != -1)
    {
        switch (option_symbol) {
            case 'h':
                requests.help_requested = true;
                break;
            case 'i':
                requests.interactive_requested = true;
                break;
            case 't':
                requests.test_requested = true;
                break;
            case 'p':
                requests.prank_requested = true;
                break;
            case 'l':
                logger_set_priority(str_to_enum(optarg));
                break;
            case '?':
                break;
            default:
                printf("?? getopt возвратило код символа 0%d ??\n", option_symbol);
        }
    }

    if (requests.help_requested)
        help();

    if (requests.test_requested)
        global_test();

    if (requests.prank_requested)
        prank();

    if (requests.interactive_requested ||
        (!requests.help_requested && !requests.test_requested && !requests.prank_requested))
        interactive_mode();


    error_in_file = logger_finish();
    MY_ASSERT(error_in_file == NO_ERROR);

    return 0;
}

enum LoggerPriority str_to_enum(char* ch)
{
    if (strcmp(ch, "debug") == 0)
        return LOGGER_PRIORITY_DEBUG;
    if (strcmp(ch, "info") == 0)
        return LOGGER_PRIORITY_INFO;
    if (strcmp(ch, "warning") == 0)
        return LOGGER_PRIORITY_WARNING;
    if (strcmp(ch, "error") == 0)
        return LOGGER_PRIORITY_ERROR;
    if (strcmp(ch, "critical") == 0)
        return LOGGER_PRIORITY_CRITICAL;
    if (strcmp(ch, "nothing") == 0)
        return LOGGER_PRIORITY_NOTHING;
    return LOGGER_PRIORITY_ERROR;
}
