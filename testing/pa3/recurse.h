//
//  recurse.h
//  
//
//  Created by Abhishek Saha on 3/11/14.
//
//

#ifndef _recurse_h
#define _recurse_h
#include "sorted-list.h"

char *getNewPath(char *dirName,char *newItemName);
char *testRemove(char *curPath);

void recurse(char *path, FILE* buffer);

extern SortedListPtr rust;

#endif
