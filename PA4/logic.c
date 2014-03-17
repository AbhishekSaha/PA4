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

 NodePtr NCreate(char * name){
 
 NodePtr first = (NodePtr)malloc(sizeof(Node));
 char * temp = malloc(strlen(name)+1);
 strcpy(temp, name);
 first->name = temp;
 first->next = NULL;
 
 return first;
 }
 
 void NDestroy(NodePtr dest){
 
 free(dest->name);
 free(dest);
 return;
 }
 
 

int main(int argc, const char * argv[])
{
    
   
    
    HashBucket * current_token;   //This looks up the first sorted list
    HASH_FIND_STR(tokens, cur_key , current_token);
    SortedListPtr init = current_token->list;
    NodePtr sptr = init->head;
    
   
    SortedListPtr buffer = (SortedListPtr)malloc(sizeof(SortedList)); //This sets up the buffer
    NodePtr fir = NCreate(sptr->name); buffer->head = fir;
    NodePtr nex; sptr = sptr->next; NodePtr buf_head = buffer->head;
    
    
    while(sptr!=NULL){ //This initializes the buffer to hold the contents of the first sortedlist
        
        nex = NCreate(sptr->name);
        buf_head->next  = nex;
        buf_head = buf_head->next;
        sptr = sptr->next;
        
    }
    
    sptr = buffer->head; //Prep for the loop  
    SortedListPtr temp;
    char * buff_key;
    
     
    int i = 2;
    for(i=2; i<args; i++){  //This compares the various sorted lists
        
        buff_key = argv[i];  //Ignore this for now
        HASH_FIND_STR(tokens, buf_key , current_token);
        temp = current_token->list;
        NodePtr ptr = temp->head;  //We now have ptr pointing to the head of the i-th sorted list
                                  //and sptr pointing to the head of the buffer sorted list
     
     
     
        while(ptr!=NULL || sptr!=NULL){  //This is a basic way to compare the respective nodes in the 
                                         //two sorted lists
            int result = compareStrings(ptr->name, sptr->name);
            
            if(result==0){
                sptr = sptr->next;
                ptr = ptr->next;
            }
            
            else if(result<0){
                prev = sptr;
                prev->next = sptr->next;
                sptr->next = NULL;
                NDestroy(sptr);
                sptr = prev->next;
            }
            
            else{
                
                ptr = ptr->next;
                
            }
            
            
        }
        
        sptr->next = NULL;         //If the buffer has nodes left to be compared, it means that they're not
                                   //present in the second sorted list. Thus, they fail the AND comparison.
        
     
     sptr = buffer->head; //Resets the pointer to the head of the buffer
    }
    
    
    
}

