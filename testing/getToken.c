#include <stdio.h>

int getLineCount(FILE *myFile)
{
	char c;
	int charCount;
	charCount = 0;

	while((c = getc(myFile)) != '\n')
		charCount++;

	rewind(myFile);

	return charCount;
}

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


	int end;
	end = strlen(token)-1;	
	token[end] = '\0';
}


int main(int argc, char **argv)
{
	char *file = argv[1];
	FILE *filePtr = fopen(file,"r");

	int lineCount;
	lineCount = getLineCount(filePtr);
	char line[lineCount];
	fgets(line,lineCount+1,filePtr);

	int space;
	space = lineCount-8;
	char token[space];

	long size;
	int i;

	extractToken(line,token);
	printf("token is: %s\n",token);

	


	printf("Line is: %s\n",line);
	
	return 0;
}
