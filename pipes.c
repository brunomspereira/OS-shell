#include "shell.h"

int containsPipe(int numArgs, char **args)
{
    int i;
    for(i = 0; i < numArgs; i++)
    {
        if(args[i][0] == '|')
            return i;
    }
    return -1;
}