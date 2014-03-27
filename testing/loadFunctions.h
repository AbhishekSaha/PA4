#ifndef GETPATH_H
#define GETPATH_H 
#include <stdio.h>
#include <stdlib.h>

//Header file for getPath
int load(char *file);
void extractToken(char *line, char *token);
int getListingLength(char *beg);
int extractFrequency(char *listing,int frequency);
char *extractPath(char *listing, char *listStart);
void extractListing(char *line, char *listStart,char *listing);
char *moveToNextListing(char *listStart);
int getMaxLineCount(FILE *filePtr);

#endif
