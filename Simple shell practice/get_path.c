#include "shell_library.h"

/**
*get_location: find a command in PATH
*@command: the command to be entered
*
*Return: If an error occurs or the command is not located - NULL.
*         Otherwise - gives the full pathname of the command.
*/
char *get_location(char *command)
{
    char *path, *path_copy, *path_token, *file_path;
    int command_length, directory_length;
    struct stat buffer;
    extern char **environ;


    path = _getenv(environ, "PATH");

    if (path) {
        path_copy = _strdup(path);
        command_length = _strlen(command);
        path_token = strtok(path_copy, ":");

        while (path_token != NULL){

            directory_length = _strlen(path_token);
            file_path = malloc(command_length + directory_length + 2);
            _strcpy(file_path, path_token);
            _strcat(file_path, "/");
            _strcat(file_path, command);
            _strcat(file_path, "\0");

            if (stat(file_path, &buffer) == 0){
                free(path_copy);
                return (file_path);
            }
            else{
                free(file_path);
                path_token = strtok(NULL, ":");
            }

        }

        free(path_copy);

        if (stat(command, &buffer) == 0)
        {
            return (command);
        }

        return (NULL);
    }

    return (NULL);
}
