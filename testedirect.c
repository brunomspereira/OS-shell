#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define FILE_MODE (S_IRUSR|S_IWUSR) 

int main(void)
{
	int fd;

	char nome[]="cat";
	char *agrs[2];
	args[0]=nome;
	args[1]=NULL;

	fd=open("input.txt", O_RDONLY);

	if(fd<0)
	{
		fprintf(stderr,"open error");
		return 1;
	}

	//close(STDIN_FILENO);
    //dup(fd); é equivalente ao abaixo // dup() cria uma copia do file descriptor usando o menor numero que nao foi usado para o novo file descriptor
    dup2(fd,STDIN_FILENO);
    close(fd);

    fd=creat("output.txt",FILE_MODE);

    if(fd<0)
	{
		fprintf(stderr,"creat error");
		return 1;
	}

	dup2(fd, STDOUT_FILENO);
	close(fd);

	execvp(nome,args);
	return 0;
}