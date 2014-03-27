#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "logic.h"

void poll()
{
	char query[500];
	while(strcmp(query,"q") != 0)
	{
		printf("Enter your query: ");
		fgets(query,500,stdin);
        
        
		char *temp;
		temp = query;
		int tokenCount;
        tokenCount = 0;
		while(*temp != '\n')
		{
			if(*temp == ' ')
				tokenCount++;
			temp++;
		}
        
		*temp = '\0';
        
		
		
        
		int i;
		i = 0;
        
        
        
		int j;
		j = 0;
        
		
        
		char *command = *brokens;
		char *temp2;
		temp2 = command;
        
		while(*temp2 != '\0')
		{
			tolower(*temp2);
			temp2++;
		}
        
		if(strcmp(command,"sa") == 0)
		{
			if(*(brokens+1) != NULL)
				sa(tokenCount, brokens);
			else
				printf("\nNot enough input arguments for query.\n");
		}
		else if(strcmp(command,"so") == 0)
		{
			if(*(brokens+1) != NULL)
				so(tokenCount, brokens);
			else
				printf("\nNot enough input arguments for query.\n");
		}
		else if(strcmp(command,"q") == 0)
		{
			printf("Exiting the program...\n");
			exit(0);
		}
		else
		{
			printf("Invalid input. Please enter commands in the following format:\n");
			printf("\tsa <token1> <token2> ...\n");
			printf("\tso <token1> <token2> ...\n");
			printf("\tq\n");
		}
        
	}
}
