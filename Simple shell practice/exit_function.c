#include "shell_library.h"

void exit_function(char **exit_args)
{
    int status = EXIT_SUCCESS;

    if (exit_args[1])
    {
        status = _atoi(exit_args[1]);
    }

    free(exit_args);
    exit(status);
 }