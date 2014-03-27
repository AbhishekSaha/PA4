#include <stdio.h>
#include <stdlib.h>
#include "process.h"
#include "uthash.h"
#include "logic.h"
#include <string.h>
void extractToken(char *line, char *token)
{
        int tokenCount;
        tokenCount = 0;


        char start;
        int lineStart;
        lineStart = 8;
        start = line[lineStart];

        while(isalnum(start))
        {
                token[tokenCount] = start;
                tokenCount++;
                lineStart++;
                start = line[lineStart];
        }

//	printf("Token before termination is: %s\n",token);
//        int end;
 //       end = strlen(token);
        token[tokenCount] = '\0';
//	printf("The token is now: %s\n",token);
}


int getListingLength(char *beg)
{
	int charCount;
	charCount = 0;

	while(*beg != ')')
	{
		charCount++;
		beg++;
	}

	return charCount;
}

int extractFrequency(char *listing,int frequency)
{

	int counter;
	counter = 0;

	while(listing[counter] != ',')
		counter++;
	
	int i;
	i = 0;
	counter++;

	while(isdigit(listing[counter])!= 0)
	{
		i++;
		counter++;
	}

	char freq[i+1]; // make space for the null character
	counter -= i;
	i = 0;

	while(isdigit(listing[counter]) != 0)
	{
		freq[i] = listing[counter];
		i++;
		counter++;
	}

	freq[i] = '\0';
	frequency = atoi(freq);
	return frequency;	
}

char *extractPath(char *listing, char *listStart,char *path)
{
	int pathCount;
	pathCount = 0;

	while(*listStart != ' ')
	{
		pathCount++;
		listStart++;
	}
	
	while(*listStart != '(') // rewind
		listStart--;
	
	listStart++;
//	char path[pathCount];
	int i;
	i = 0;
	
	while(*listStart != ' ')
	{
		path[i] = *listStart; // copying it into the array
		i++;
		listStart++;
	}

	path[pathCount] = '\0';
//	char *myPath;
//	myPath = path;
	return path;
}

void extractListing(char *line, char *listStart,char *listing)
{

	int counter;
	counter = 0;

	while(*listStart != ')')
	{
		listing[counter] = *listStart;
		counter++;
		listStart++;
	}
	listing[counter] = '\0';

}

char *moveToNextListing(char *listStart)
{
	
	while((*listStart != '(') && (*listStart != '\n'))
		listStart++;
	

	if(*listStart == '\n')
		return listStart;
	
	listStart++;
/*
	while(*listStart != ')')
	{
		printf("%c",*listStart);
		listStart++;
	}
	printf("\n");
*/
	return listStart;
	
}

int getMaxLineCount(FILE *filePtr)
{
	char c;
        int lineCount;
        int maxCount;
        lineCount = 0;
        maxCount = 0;
        while(c != EOF)
        {
                c = fgetc(filePtr);
                lineCount++;
                if((c == '\n') && (lineCount > maxCount))
                {
                        maxCount = lineCount;
                        lineCount = 0;
                }
	}

	rewind(filePtr);
	return maxCount;
}


int load(char *file)
{
        FILE *filePtr = fopen(file,"r");

	if(filePtr == NULL)
		return 0;

        // get the max size of the line
        int lineCount;
        lineCount = getMaxLineCount(filePtr);
        char line[lineCount];

        // max size for a listing
        int listingLength;
        listingLength = lineCount;
        char listing[lineCount];

	char *actualToken;

	NNodePtr him = (NNodePtr)malloc(sizeof(NNode));

	FILE *aux = fopen("aux.txt","w");

        while(fgets(line,lineCount,filePtr) != NULL)
        {
                char *listStart;
                char *head;
                head = &line[0];
                listStart = &line[1];

                int frequency;
                char *path = (char *)malloc(lineCount);



                if(*head  == '<')
                {
                        head++;
                        if(*head != '/')
                        {
				int space;
                                space = lineCount-8;
				
				char *token;
				token = (char *)malloc(space);
                                
                                extractToken(line,token);
				actualToken = token;
				printf("The token in load is: %s\n",token);
                        } 
                        else if(*head == '/')
                               continue; 
                }
		else if(*head == '(')
                {
                        extractListing(line,listStart,listing);
                        while(*listStart != '\n')
                        {
                                frequency = extractFrequency(listing,frequency);
                                path = extractPath(listing,listStart,path);
                               
				printf("Frequency is: %d. Path is: %s. actualToken is: %s\n",frequency,path,actualToken);
//				NNodePtr him = (NNodePtr)malloc(sizeof(Node));
				him->key = actualToken;
				him->filename = path;
			
				fprintf(aux,path);
				fprintf(aux," ");
				fprintf(aux, actualToken);
				fprintf(aux,"\n");

                            
				listStart = moveToNextListing(listStart);
	
                        }
                }
                else
                      continue; 
		
        }
	fclose(aux);
/*
	
*/
	process("bil", "rondo");
    
    printf("exited process\n");
   
return 1;
}
