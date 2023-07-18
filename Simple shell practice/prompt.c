#include "shell_library.h"
#include <sys/wait.h>


int main(int ac, char **argv)
{
    char *string = NULL;
    int i, j, status;
    size_t n = 0;
    ssize_t number_character;
    pid_t child_pid;

    (void)ac;

    while (1)
    {
	if (isatty(STDIN_FILENO))
	{
		printf ("cisfun$ ");
	}

        number_character = getline(&string, &n, stdin);
        if (number_character == -1)
        {
            free(string); 
            exit(EXIT_FAILURE);
        }

        i = 0;
        while (string[i])
        {
            if (string[i] == '\n')
            {
                string[i] = 0 ;
            }
            i++;    
        }

        j = 0;
        argv[j] = strtok(string, " ");
        while (argv[j])
        {
            j++;
            argv[j] = strtok(NULL, " ");
        }

        child_pid = fork();
        if (child_pid == -1)
        {
            free(string);
            exit(EXIT_FAILURE);
        }
        if (child_pid == 0)
        {
            execution_command(argv);
        }
        else
            wait(&status);
    }

    return(0);
}

 
