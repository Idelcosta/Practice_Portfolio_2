#include "shell_library.h"

void exit_function(char **exit_args, size_t args_count)
{
    int status = EXIT_SUCCESS;

    if (exit_args[1])
    {
        status = atoi(exit_args[1]);
    }

    free(exit_args, args_count);
    exit(status);
 }