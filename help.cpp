#include "help.h"

#include <stdio.h>
#include <stdlib.h>

#include "logger.h"

void help()
{
    system("ncal");
    logger_output("help(): calender printed\n", LOGGER_PRIORITY_INFO);

    printf("parameter help\n");
    printf("--interactive  Sets interactive mode\n");
    printf("--test         Sets the test mode\n");
    printf("--prank        Ha-ha-ha\n");

    printf("Logger priority flags:\n");
    printf("--logger=");
    printf("debug        Sets the fifth logger priority\n");
    printf("info         Sets the fourth logger priority\n");
    printf("warning      Sets the third logger priority\n");
    printf("error        Sets the second logger priority\n");
    printf("critical     Sets the first logger priority\n");
    printf("If you do not enter a logger flag, there will be no logger_output\n");

    logger_output("help(): possible argv printed\n", LOGGER_PRIORITY_INFO);
}
