#include "shell.h"

/**
* main - Simple Shell main func
* @ac: argument count
* @av: Arguments
* Return : 0 Always (Success)
*/
int main(int ac, char **av)
{
    char *line = NULL;
    char **cmd = NULL;
    int status = 0;
    int i;
    (void) ac;
    (void) av;
    

    while(1)
    {
        line = read_cmd();
        if (line == NULL)
        {
            if (isatty(STDIN_FILENO))
                write(STDOUT_FILENO, "\n",1);
            return (status); //handling of crtl + d (when it reach EOF)
        }
        // printf("%s", line); /*test read_cmd*/
        cmd  = func_token(line);

        if (!cmd)
        {
            continue;
        }
        for (i = 0; cmd[i]; i++)
        {
            printf("%s\n", cmd[i]);
            free(cmd[i]), cmd[i] = NULL;
        }
        free(cmd), cmd = NULL;
        // status = func_exec(cmd,av);
    }
}
