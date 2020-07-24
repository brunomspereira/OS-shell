#include "shell.h"

//redirects are handled in reverse order
//2> >>> <

#define FILE_MODE (S_IRUSR | S_IWUSR)

int redirects(int numargs, char *args[])
{
    int fd;
    if (numargs<3)
        return 0;

    if (strcmp(args[numargs-2],"2>")==0)
    {
        fd=creat (args[numargs-1],FILE_MODE | S_IRGRP | S_IROTH);
        if(fd<0)
        {
            return -1; //indica um erro
        }
        dup2(fd,STDERR_FILENO);
        close(fd);
        args[numargs-2]=NULL;
        numargs=numargs-2;
    }

    if((strcmp(args[numargs-2], ">>"))==0)
    {
        fd = open(args[numargs-1],O_WRONLY|O_APPEND);
        if(fd < 0)
        {
            return -1;
        }
        dup2(fd, STDOUT_FILENO);
        close(fd);
        args[numargs-2]=NULL;
        numargs=numargs-2;
    }

    if((strcmp(args[numargs-2],">"))==0)
    {
        fd = creat(args[numargs-1],FILE_MODE);
        if(fd < 0)
        {
            return -1;
        }
        dup2(fd, STDOUT_FILENO);
        close(fd);
        args[numargs-2]=NULL;
        numargs=numargs-2;
    }
    
    if(strcmp(args[numargs-2],"<")==0)
    {
        fd = open(args[numargs-1],O_RDONLY);
        if(fd < 0)
        {
            return -1;
        }
        dup2(fd, STDIN_FILENO);
        close(fd);
        args[numargs-2]=NULL;
        numargs=numargs-2;
    }
    /*else
    {
        printf("Símbolo não reconhecido\n");
    }*/
    
    return numargs;
}