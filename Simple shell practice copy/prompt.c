#include "shell_library.h"
#include <sys/wait.h>

#define MAX_COMMAND 10
#define MAX_COMMAND_LENGTH 100

void display_prompt(char **av, char **env)
{
    char *string = NULL;
    int i, j, status;
    size_t n = 0;
    ssize_t number_character;
    char *argv[] = {MAX_COMMAND};
    pid_t child_pid;

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

        char *path = getenv("PATH");
        char *path_copy = strdup(path);
        argv[j] = strtok(path_copy, " ");
        int command_found = 0;
        while (argv[j] != NULL)
        {
            char executable[MAX_COMMAND_LENGTH];
            snprintf(executable, sizeof(executable), "%s/%s", dir, command);
             // Attempt to execute the command
            if (access(executable, X_OK) == 0) {
                // Command found and executable
                command_found = 1;
                break;
            }   
            j++;
            argv[j] = strtok(NULL, " ");
        }

        if (command_found) {
            // Execute the command
            execlp(command, command, NULL);

            // If execlp returns, an error occurred
            perror("execlp");
            exit(1);
        } else {
            // Command not found
            printf("Command not found: %s\n", command);
        }

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
                printf ("%s: No such file or directory\n", av[0]);
            }
        }
        else
            wait(&status);
    }
}

 
