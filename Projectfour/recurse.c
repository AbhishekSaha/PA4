#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include "tokenize.c"
#include "recurse.h"

SortedListPtr rust;
char *getNewPath(char *dirName,char *newItemName)
{
    
	strcat(dirName,"/");
    strcat(dirName,newItemName);
    
    return dirName;
}

char *testRemove(char *curPath)
{
	char *ptr;
    
	ptr = strrchr(curPath,'/');
	
	if(ptr != NULL)
	{
		*ptr = '\0';
	}
	
	return curPath;
}


void recurse(char *path, FILE *bufferPtr)
{
    
	
	DIR *dirPtr;
	dirPtr = opendir(path); 
    
	FILE *filePtr = fopen(path,"r");
    
    
	if(dirPtr != NULL) // Non-null value means success
	{
		struct dirent *direntPtr = readdir(dirPtr);
        
		while(direntPtr != NULL)
		{
			if(strcmp(direntPtr->d_name,".") == 0)
			{
				direntPtr = readdir(dirPtr);
			}
			else if(strcmp(direntPtr->d_name,"..") == 0)
			{
				direntPtr = readdir(dirPtr);
			}
			else
			{
				char *newPath = getNewPath(path,direntPtr->d_name);
				recurse(newPath,bufferPtr);
                
				// remove the last part of the path so that the next element doesn't get it
				path = testRemove(newPath);
				direntPtr = readdir(dirPtr);
			}
		}
        
	}
	else if(filePtr != NULL)
	{
		processFile(path,bufferPtr);
		return;
	}
	else
	{
		printf("\nThere's an error\n");
	}
	
	return;
}

int checkFile(char *file)
{
        char temp[25];
        strcpy(temp,file);

        

        char bob[4];

        int length = strlen(temp);

        


        bob[3] = temp[length];
        bob[2] = temp[length -1];
        bob[1] = temp[length - 2];
        bob[0] = temp[length - 3];

        

        return strcmp(bob,"txt");
}


int main(int argc, char **argv)
{
	char *indexFile;
	indexFile = argv[1];
    
	FILE *bufferPtr = fopen("aux.txt","w");
	
	if(checkFile(indexFile) != 0)
	{
		printf("Not a valid file name. Please enter a file with a .txt extension\n");
		return 0;
	}
    
	DIR *dirPtr;
	dirPtr = opendir(argv[2]);
	FILE *filePtr = fopen(argv[2],"r");
	
	if(dirPtr != NULL)
	{
		recurse(argv[2],bufferPtr);
		
	}
	else if(filePtr != NULL)
	{
		processFile(argv[2],bufferPtr);
		
	}
	else
		printf("There is an error in your input. Please make sure that the input is the path to an existing file or directory. Exiting...\n");
    fclose(bufferPtr);
	process("bill", "rondo");
    printAll(indexFile);
	
	remove("aux.txt");

return 0;
}







































