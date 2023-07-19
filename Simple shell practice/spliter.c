#include "shell_library.h"

char* my_strtok(char* str, char *delim) 
{
    static char* nextTokenStart = NULL;
    char* tokenStart = (str != NULL) ? str : nextTokenStart;
    char* tokenEnd;
    
    if (tokenStart == NULL || *tokenStart == '\0') {
        return NULL; 
    }
    
    tokenEnd = tokenStart;
    
    while (*tokenEnd != *delim && *tokenEnd != '\0') {
        tokenEnd++;
    }
    
    if (*tokenEnd == *delim) {
        *tokenEnd = '\0';  
        nextTokenStart = tokenEnd + 1;  
    } else {
        nextTokenStart = NULL;  
    }
    
    return tokenStart;
}