#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "loadFunctions.h"
#include "poll.h"
#include "logic.h"
#include "uthash.h"


int isEmpty(FILE *file)
{
	long savedOffset = ftell(file);
	fseek(file,0,SEEK_END);

	if(ftell(file) == 0)
		return 1;

	fseek(file, savedOffset, SEEK_SET);
	
	return 0;
}



int main(int argc, char **argv)
{
	if(argv[1] == NULL)
	{
		printf("Error: no index file was input. Exiting...\n");
		exit(0);
	}	
	else if(argv[2] != NULL)
	{
		printf("Error: too many input arguments. Exiting...\n");
		exit(0);
	}
	else
	{
		if(access(argv[1],F_OK) == -1)
		{	
			printf("Error: The input file does not exist. Exiting...\n");
			exit(0);
		}
	
		
		FILE *temp = fopen(argv[1],"r");
		if(isEmpty(temp) == 1)
		{
			printf("Error: Index file is empty. Exiting...\n");
			exit(0);
		}
		
	}
/*	else if(argv[1] != NULL)
	{
		char *temp = argv[1];
		int length = strlen(argv[1]);
		int dot;
		int t;
		int x;
		int T;
		
//		dot = temp[length-3] == '.' ? 0: 1;
		t = temp[length-2] == 't' ? 0: 1;
		x = temp[length-1] ==' x' ? 0: 1;
		T = temp[length] == 't' ? 0: 1;

	
		if((dot != 0) && (t != 0) && (x != 0) && (T != 0))
		{	
			printf("Error: input file is not a text file. Exiting...\n");
			exit(0);
		}
	}
*/		
		
	char *file = argv[1];

	int something;
	something = load(file);

	remove("aux.txt");

	if(something == 0)
	{
		printf("Error: The file you input is not valid. Exiting...\n");
		exit(0);
	}
	else if(something == 1)
		poll();

return 0;


}
