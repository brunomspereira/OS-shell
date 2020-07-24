#include "shell.h"

void calc(char *op1, char *op, char *op2){
	double value1 = atof(op1);
	double value2 = atof(op2);
	double resultado = 0.00;

	switch(op[0])
	{
		case '+':
			resultado = value1+value2;
			printf("%.2f\n", resultado);
		break;

		case '-':
			resultado = value1-value2;
			printf("%.2f\n", resultado);
		break;

		case '*':
			resultado = value1*value2;
			printf("%.2f\n", resultado);
 		break;

		case '/':
			if(value2 == 0)
				perror("Impossivel divisao por zero\n");
			else{
				resultado = value1/value2;
				printf("%.2f\n", resultado);
			}
		break;

		case '^':
			resultado = powf(value1, value2);
			printf("%.2f\n", resultado);
		break;
	}
}

void bits(char *op1, char *op, char *op2){
	int value1 = atoi(op1);
	int value2 = atoi(op2);

	switch(op[0])
	{
		case '&':
			printf("%d\n", value1&value2);
		break;

		case '|':
			printf("%d\n", value1|value2);
		break;

		case '^':
			printf("%d\n", value1^value2);
		break;

		case '<':
			printf("%d\n", value1<<value2);
		break;

		case '>':
			printf("%d\n", value1>>value2);
		break;
		
		case '~':
			printf("%d %d\n", (~value1),(~value2));
		break;
	}
}