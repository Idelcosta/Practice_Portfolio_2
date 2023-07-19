#include "shell_library.h"

char *get_location(char *command)
{
    char *path, *path_copy, *path_token, *file_path;
    int command_length, directory_length, del1_count, del2_count;
    struct stat buffer;
    char del1 = "/", del2 = "\0";

    path = getenv("PATH");

    if (path) {
        path_copy = strdup(path);
        command_length = strlen(command);
        path_token = strtok(path_copy, ":");

        while (path_token != NULL){

            directory_length = strlen(path_token);
            del1_count = strlen(del1);
            del2_count = strlen(del2);
            file_path = malloc(command_length + directory_length + 2);

            _strncpy(file_path, path_token, directory_length);
            _strncat(file_path, del1, del1_count);
            _strncat(file_path, command, command_length);
            _strncat(file_path, del2, del2_count);

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
