#include "shell_library.h"

/**
*main - input the command and create child proccess to execute it
*@ac: count the strings entered
*@argv: number of strings read in
*
*Return: 0
*/
int main(int ac, char **argv)
{
    char *string = NULL, *string_copy = NULL, *arguments;
    int i, status, string_length, arguments_count = 0;
    size_t n = 0, number_character;
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
        string_copy = malloc(sizeof(char) * number_character);
        if (string_copy == NULL)
        {
            perror("error memory allocation");
            return (-1);
        }
        string_length = _strlen(string);
        _strncpy(string_copy, string, string_length);
        arguments = strtok(string, " \n");
        while (arguments != NULL)
        {
            arguments_count++;
            arguments = strtok(NULL, " \n");
        }
        arguments_count++;
        argv = malloc(sizeof(char *) * arguments_count);
        arguments = strtok(string_copy, " \n");
        for (i = 0; arguments != NULL; i++){
            argv[i] = malloc(sizeof(char) * _strlen(arguments));
            _strncpy(argv[i], arguments, string_length);

            arguments = strtok(NULL, " \n");
        }
        argv[i] = NULL;
        void pid_execution()
    }
    free(string);
    free(string_copy);
    return(0);
}

/**
*pid_executiont: create child process and execute the commands
*/
void pid_execution()
{
    char **argv;
    size_t n = 0, number_character;
    char *string = NULL;

    if (check_builtin(argv, number_character))
        continue;

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