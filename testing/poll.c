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
	
		char *tokens[tokenCount];
		int i;
		i = 0;
	
		tokens[i] = strtok(query," ");
		while(tokens[i] != NULL)
		{
			i++;
			tokens[i] = strtok(NULL," \n");
		}
	
	
		int j;
		j = 0;
	
		while(j != i)
		{
			printf("tokens[%d] is: %s\n",j,tokens[j]);
			j++;
		}
	
		char *command = tokens[0];
		char *temp2;
		temp2 = command;
	
		while(*temp2 != '\0')
		{
			tolower(*temp2);
			temp2++;
		}
	
		if(strcmp(command,"sa") == 0)
		{
			if(tokens[1] != NULL)
				sa(tokenCount, tokens);
			else
				printf("\nNot enough input arguments for query.\n");
		}
		else if(strcmp(command,"so") == 0)
		{	
			if(tokens[1] != NULL)
				so(tokenCount, tokens);
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

