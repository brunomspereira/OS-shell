#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <ctype.h>
#include <math.h>
#include <dirent.h>
#include <time.h>

typedef struct 
{ 
	char msg[100]; 
	int tempo;
} aviso_t;

typedef struct 
{ 
	char fonte[100]; 
	char destino[100];  
} copiar_t;


int parse(char *buf, char **args);

void execute(char **args, int N);

int builtin (char **args, int N);

void socp(char *fonte, char *destino);

int isjpg(int fD);

void calc(char *op1, char *op, char *op2);

void bits(char *op1, char *op, char *op2);

int redirects(int numargs, char *args[]);

int containsPipe(int numArgs, char **args);

void aviso (char *mesg, int tempo);

void * avisowrapper (void *args);

void socpth(char* fonte, char* destino);

void * socpthwrapper(void *args);

void maior( char *file1, char *file2);

/*int sols(int argc,char **argv);*/ 

/* constantes que podem tornar uteis*/

#define BG 0
#define FG 1
