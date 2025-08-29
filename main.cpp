#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

#include "io.h"
#include "equation_solver.h"
#include "colors_codes.h"
#include "my_static_assert.h"
#include "my_assert.h"

#include "global_test.h"
#include "interactive_mode.h"
#include "help.h"
#include "prank.h"

#include "logger.h"

enum LoggerPriority str_to_enum(char* ch);

int main(const int argc, char** argv)
{
    bool help_requested = false;
    bool interactive_requested = false;
    bool test_requested = false;
    bool prank_requested = false;

    FILE* logger_file = logger_init();
    logger_set_priority(LOGGER_PRIORITY_NOTHING);

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
                help_requested = true;
                break;
            case 'i':
                interactive_requested = true;
                break;
            case 't':
                test_requested = true;
                break;
            case 'p':
                prank_requested = true;
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

    if (help_requested) {
        help();
    }

    if (test_requested) {
        global_test();
    }

    if (prank_requested) {
        prank();
    }

    if (interactive_requested || (!help_requested && !test_requested && !prank_requested)) {
        interactive_mode();
    }

    logger_finish(logger_file);
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
    return LOGGER_PRIORITY_NOTHING;
}
