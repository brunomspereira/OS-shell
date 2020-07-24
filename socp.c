#include "shell.h"
void ioCopy (int IN, int OUT);

void socp(char *fonte, char *destino)
{
	int fdOR = open(fonte, O_RDONLY);
    int fdDS = creat(destino, S_IRUSR|S_IWUSR);

    ioCopy(fdOR, fdDS);
}

void ioCopy (int IN, int OUT)
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