//
//  main.c
//  Perg3a
//
//  Created by Abhishek Saha on 3/11/14.
//  Copyright (c) 2014 Abhishek Saha. All rights reserved.
//
#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <dirent.h>
#include "process.h"
#include "uthash.h"
#include "sl.h"
#include "recurse.h"
#include "sorted-list.h"

HashBucket *tokens;
SortedListPtr rust;

int name_sort(HashBucket * a, HashBucket *b) {
    return strcmp(a->name,b->name);
}

int compareInts(void *p1, void *p2)
{
	int i1 = *(int*)p2;
	int i2 = *(int*)p1;
    
	return i1 - i2;
}

int compareStrings(void *p1, void *p2)
{
	char *s1 = p1;
	char *s2 = p2;
	return strcmp(s1, s2);
}


void process(char *myToken, char *myFilePath) //Change the parameters to (char * str1, char * str2)
{
    
    
    
    rust = SLCreate(compareStrings);
    
    
    char * buffer= (char*)malloc(101);
    FILE * f = fopen("aux.txt", "r");
    char * trok = (char*)malloc(101);
    
    
    
    
    NNodePtr him = (NNodePtr)malloc(sizeof(NNode));
    while(fscanf(f, "%s %s", buffer, trok)!=EOF){
        
        
        char * copyone = malloc(strlen(trok)+1);
        strcpy(copyone, trok);
        char * copytwo = malloc(strlen(buffer) +1);
        strcpy(copytwo, buffer);
        him->key = copyone; him->filename = copytwo;
        
        insert(him);
        Insert(rust, him->key, him->key);
        
        //free(him);
        //him = (NNodePtr)malloc(sizeof(NNode));
        //  printAll();
        
    }
    
    
    
    fclose(f);
    
    
    // printAll();
    
    return;
    
}

void insert(NNodePtr item){
    HashBucket * current_token;
    char * KEY = item->key;
    HASH_FIND_STR(tokens, KEY , current_token);
    
    printf("KEY: %s\n", KEY);
    if(current_token==NULL){
        current_token = (HashBucket*)malloc(sizeof(HashBucket));
        current_token->name = item->key;
        
        
        CompareFuncT c = compareInts;
        SortedListPtr temp = SLCreate(c);
        int * one = malloc(sizeof(int));
        *one  = 1;
        
        int success;
        success = SLInsert(temp, (void*)one, item->filename);
        current_token->list = temp;
        HASH_ADD_STR(tokens, name, current_token);
        
        //        free(item);
    }
    else{
        printf("Entered process\n");
        SortedListPtr temp = current_token->list;
        int success = 0;
        int * one = malloc(sizeof(int));
        *one  = 1;
        
        void*zone = (void*)one;
        success = SLInsert(temp, zone, item->filename);
        current_token->list = temp;
        HASH_DEL(tokens, current_token);
        HASH_ADD_STR(tokens, name, current_token);
        //free(item);
    }
    
    return;
}


int printAll(char * path){
    
    NodePtr temp = rust->head;
    NodePtr pr;
    FILE * f = fopen(path, "w");
    //  FILE * f = fopen(path, "w");
    while(temp!=NULL){
        
        HashBucket * current_token;
        char * KEY = temp->name;
        HASH_FIND_STR(tokens, KEY , current_token);
        
        
        if(current_token==NULL){
            break;
        }
        
        
        else{
            SortedListPtr buff = current_token->list;
            NodePtr ptr = buff->head;
            NodePtr prev; NodePtr tomp;
            fprintf(f, "<List> (%s)\n </List>",KEY);
            
            while(ptr!=NULL){
                
                char * filename = ptr->name;
                int jer = *(int*)ptr->data;
                fprintf(f,"(%s ,%d)", filename, jer);
                prev = ptr;
                ptr = ptr->next;
                
                if(ptr!=NULL){
                    fprintf(f,"-> ");}
                
                
            }
            free(prev->data); free(prev->name); free(prev->next);
            free(prev);
            fprintf(f,"\n\n");
            free(current_token->list);
            pr = temp;
            if(temp->next==NULL){
                break;
            }
            temp = temp->next;
            
            if(temp!=NULL){
                while(strcmp(pr->name, temp->name)==0){
                    temp = temp->next;
                    if (temp==NULL) {
                        break;
                    }
                }
                
            }
            
                    continue;}
                
    }
    
            
            free(rust);
            free(tokens);
            fclose(f);
            
            return 1;
        }
