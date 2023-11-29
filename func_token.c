#include "shell.h"

char **func_token(char *line)
{
    char *token = NULL , *tmp = NULL;
    char **cmd = NULL;
    int count = 0 , i = 0;

    if (!line)
        return (NULL);
    tmp = _strdup(line);
    token = strtok(line, DELIM);

    if (token == NULL)
    {
        free(line), line = NULL;
        free(tmp), tmp = NULL;
        return (NULL);
    }

    while (token)
    {
        count++;
        token = strtok(NULL, DELIM);
    }
    free(tmp), tmp = NULL;

    cmd = malloc(sizeof(char *) * (count + 1));
    if (cmd == NULL)
    {
        free(line), line = NULL;
        return(NULL);
    }

    token = strtok(line, DELIM);
    while (token)
    {
        cmd[i] = _strdup(token);
        token = strtok(NULL, DELIM);
        i++;
    }
    free(line) , line = NULL;
    cmd[i] = NULL;
    return (cmd);

}
