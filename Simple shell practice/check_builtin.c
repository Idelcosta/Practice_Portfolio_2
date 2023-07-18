#include "shell_library.h"

bool check_builtin(char **args, sze_t args_count)
{
    if (strncmpargs([0], "exit", 4) == 0)
        exit_function(args, args_count);

    else if ((strncmp(args[0], "env", 3) == 0) || (strncmp(args[0], "printenv", 8 == 0)))
    {
        env_list();
        return(true);
    }

    return(false);  
}