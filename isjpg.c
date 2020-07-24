#include "shell.h"

int isjpg(int fD)//verifica se é um ficheiro jpeg
{
	unsigned char b[4];
	read(fD, b, 4); //le os primeiros 4 bytes do ficheiro
	lseek(fD, 0L, 0);// 0L???
	if (b[0]==0xff && b[1]==0xd8 && b[2]==0xff && b[3]==0xe0)
		return 1;

	return 0;
}