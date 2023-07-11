#include "shell_library.h"
#include <sys/wait.h>

void display_prompt(char **av, char **env)
{
    char *string = NULL;
    int i, status = 0;
    size_t n = 0;
    ssize_t number_character;
    char *argv[] = {NULL, NULL};
    pid_t child_pid;

    while (1)
    {
        print("cisfun$ ");

        number_character = getline(&string, &n, stdin);
        if (number_character == -1)
        {
            free(string); 
            exit(EXIT_FAILURE);
        }

        i = 0
        while (string[i])
        {
            if (string[i] == "\n")
            {
                string[i] = 0 ;
            }
            i++;
        }

        argv[0] = string;
        child_pid = fork();
        if (child_pid == -1)
        {
            free(string);
            exit(EXIT_FAILURE);
        }
        if (child_pid == 0)
        {
            if (execve(argv[0], argv, env) == -1)
            {
                print ("%s: No such file or directory\n", av[0]);
            }
        }
        else
            wait(&status);
    }
}

 