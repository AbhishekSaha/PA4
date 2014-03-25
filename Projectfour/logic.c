//
//  main.c
//  PA4
//
//  Created by Abhishek Saha on 3/16/14.
//  Copyright (c) 2014 Abhishek Saha. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "sorted-list.h"
#include <string.h>
#include "uthash.h"
#include "logic.h"
#include "process.h"

NodePtr NCreate(char * name){
    
    NodePtr first = (NodePtr)malloc(sizeof(Node));
    char * temp = malloc(strlen(name)+1);
    strcpy(temp, name);
    first->name = temp;
    first->data = (void*)temp;
    first->next = NULL;
    
    return first;
}

void NDestroy(NodePtr dest){
    
    free(dest->name);
    free(dest);
    return;
}

int sa(int argc, char * argv[])
{
    
    HashBucket * current_token;   //This looks up the first sorted list
    int i = 0;
    for(i=1; i<argc; i++){ //Checks if all the querys are in the hash table
        HASH_FIND_STR(tokens, argv[i] , current_token);
        if (current_token==NULL) {
            printf("Error, query not found in index\n");
            return -1;
        }
    }
    
    HASH_FIND_STR(tokens, argv[1] , current_token);
    SortedListPtr init = current_token->list;
    NodePtr sptr = init->head;
    
    
    SortedListPtr buffer = SLCreate(compareStrings); //This sets up the buffer
    
    
    
    
    while(sptr!=NULL){ //This initializes the buffer to hold the contents of the first sortedlist
        
        StringInsert(buffer, (void*)sptr->name, sptr->name);
        sptr = sptr->next;
        
    }
    
    
    sptr = buffer->head; //Prep for the loop
    SortedListPtr temp;
    char * buff_key;
    
    
    for(i=2; i<argc; i++){  //This compares the various sorted lists
        
        buff_key = argv[i];  //Ignore this for now
        HASH_FIND_STR(tokens, buff_key , current_token);
        temp = current_token->list;
        NodePtr ptr = temp->head;  //We now have ptr pointing to the head of the i-th sorted list
        //and sptr pointing to the head of the buffer sorted list
        
        NodePtr prev = NULL;
        
        
        
        
        
        while(ptr!=NULL || sptr!=NULL){  //This is a basic way to compare the respective nodes in the
            
            int result;
            result = strcmp(ptr->name, sptr->name);
            
            printf("Ptr->name: %s Sptr->name: %s Result: %d\n", ptr->name, sptr->name, result);
            
            if(result==0){
                
                prev = sptr;
                sptr = sptr->next;
                
                ptr = ptr->next;
                
            }
            
            else if(result>0){
                if (prev==NULL) {
                    buffer->head = sptr->next;
                    sptr->next = NULL;
                    NDestroy(sptr);
                    sptr = buffer->head;
                }
                
                else{
                    prev->next = sptr->next;
                    sptr->next = NULL;
                    NDestroy(sptr);
                    sptr = prev->next;}
            }
            
            else{    //file pile      ile
                
                ptr = ptr->next;
                
            }
            
        }
        printf("Got out of for loop\n");
        if(sptr!=NULL){
            sptr->next = NULL;}         //If the buffer has nodes left to be compared, it means that they're not
        //present in the second sorted list. Thus, they fail the AND comparison.

        sptr = buffer->head; //Resets the pointer to the head of the buffer
    }
    
    sptr = buffer->head;
    printf("%s", sptr->name);
    sptr = sptr->next;
    while (sptr!=NULL) {
        printf("->%s ", sptr->name);
        sptr = sptr->next;
    }
    printf("\n");
    
    return 0;
}



int so(int argc, char * argv[]){
    
    
    HashBucket * current_token;   //This looks up the first sorted list
    int i = 0;
    for(i=1; i<argc; i++){   //Checks to see if all the queries are in the hashtable
        HASH_FIND_STR(tokens, argv[i] , current_token);
        if (current_token==NULL) {
            printf("Error, query not found in index\n");
            return -1;
        }
    }
    
    HASH_FIND_STR(tokens, argv[1] , current_token);
    SortedListPtr init = current_token->list;
    NodePtr sptr;
    sptr = init->head;
    
    
    SortedListPtr buffer = SLCreate(compareStrings); //This sets up the buffer
    
    NodePtr fir = NCreate(sptr->name); buffer->head = fir;
    NodePtr nex; sptr = sptr->next; NodePtr buf_head = buffer->head;
    
    i =0;
    
    while(sptr!=NULL){ //This initializes the buffer to hold the contents of the first sortedlist
        i++;
        printf("SPtr name: %s\n", sptr->name);
        StringInsert(buffer, (void*)sptr->name, sptr->name);
        sptr = sptr->next;
    }
    
    
    sptr = buffer->head; //Prep for the loop
    SortedListPtr temp;
    char * buff_key;
    NodePtr ptr;
    for(i=2; i<argc; i++){  //This compares the various sorted lists
        
        buff_key = argv[i];
        HASH_FIND_STR(tokens, buff_key , current_token);
        temp = current_token->list;
        ptr = temp->head;
        
        int zztop = 0;
        while(ptr!=NULL){
            printf("In the for loop: I%s \n", ptr->name);
            zztop = StringInsert(buffer, (void *)ptr->name, ptr->name);
            
            ptr = ptr->next;
            
        }
        
        ptr = buffer->head;
    }
    
    
    /*For printing*/
    ptr = buffer->head;
    printf("%s", ptr->name);
    ptr = ptr->next;
    while (ptr!=NULL) {
        printf("->%s ", ptr->name);
        ptr = ptr->next;
    }
    printf("\n");
    
    return 0;
}
