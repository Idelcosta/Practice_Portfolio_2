#include "shell_library.h"

/**
*execution_command - execute the command 
*@argv: command to be executed
*/
void execution_command(char **argv)
{
    char *command = NULL, *actual_command = NULL;

    if (argv)
    {
        command = argv[0];

        actual_command = get_location(command);

        if (execve(actual_command, argv, NULL) == -1){
            perror("hsh: No such file or directory\n");
        }
        
    }

}
