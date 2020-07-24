#include "shell.h"
void soCopy (int IN, int OUT);

void socpth(char *fonte, char *destino)
{
	int fdOR = open(fonte, O_RDONLY);
    int fdDS = creat(destino, S_IRUSR|S_IWUSR);

    soCopy(fdOR, fdDS);
}

void soCopy (int IN, int OUT)
{
    int n;
    char buf[128];
    
    while((n = read(IN, buf, 128))>0) //input
        {
            if (n < 0)
                perror(NULL);

            write(OUT, buf, n);
        }
}
 

void * socpthwrapper(void *args)
{

	copiar_t *ptr = (copiar_t *)args;
	socpth(ptr->fonte, ptr->destino);
	free(ptr);
	return(NULL);
}