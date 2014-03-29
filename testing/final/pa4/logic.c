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
//    printf("Entered SA\n");
    HashBucket * current_token;   //This looks up the first sorted list
    int i = 0;
    for(i=1; i<argc; i++){ //Checks if all the querys are in the hash table
        HASH_FIND_STR(tokens, argv[i] , current_token);
        if (current_token==NULL) {
            printf("\n\tError, query not found in index\n\n");
            return -1;
        }
    //    printf("%s\n", argv[i]);
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
    SortedListPtr temp = (SortedListPtr)malloc(sizeof(SortedList));
    char * buff_key;
    
  
    for(i=2; i<argc; i++){  //This compares the various sorted lists
        
        buff_key = argv[i];  //Ignore this for now
        HASH_FIND_STR(tokens, buff_key , current_token);
        temp = current_token->list;
        NodePtr ptr = temp->head;  //We now have ptr pointing to the head of the i-th sorted list
        //and sptr pointing to the head of the buffer sorted list
        
        NodePtr prev = NULL;
        SortedListPtr pt_temp = SLCreate(compareStrings);
        while(ptr!=NULL){ //This initializes the buffer to hold the contents of the first sortedlist
            
            StringInsert(pt_temp, (void*)ptr->name, ptr->name);
            //printf("%s->", ptr->name);
            prev =ptr;
            ptr = ptr->next;
            
        }
        
//        printf("\nWorked\n");
        prev->next = NULL;
        ptr = pt_temp->head;
        
        
        
        while(1){  //This is a basic way to compare the respective nodes in the
            
            int result;
            result = compareStrings((void *)ptr->name, (void*)sptr->name);
            
  //          printf("Ptr->name: %s Sptr->name: %s Result: %d\n", ptr->name, sptr->name, result);
//   		printf("%s\n",ptr->name);         
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
            if(ptr==NULL)
                break;
            if(sptr==NULL)
                break;
            
        }
//        printf("Got out of for loop\n");
        if(sptr!=NULL){
            sptr->next = NULL;}
        if(ptr==NULL){
            prev->next = NULL;
            
        }
        
        //If the buffer has nodes left to be compared, it means that they're not
        //present in the second sorted list. Thus, they fail the AND comparison.
        
        sptr = buffer->head; //Resets the pointer to the head of the buffer
    }
    
    sptr = buffer->head;
 
/*   printf("%s", sptr->name);
    sptr = sptr->next;
    while (sptr!=NULL) {
        printf("->%s ", sptr->name);
        sptr = sptr->next;
    }
    printf("\n");
 */   

printf("\n");
	while(sptr!=NULL)
	{
		printf("\t%s\n",sptr->name);
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
            printf("\n\tError, query not found in index\n\n");
            return -1;
        }
//        printf("%s\n", argv[1]);
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
    //    printf("SPtr name: %s\n", sptr->name);
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
     //       printf("In the for loop: I%s \n", ptr->name);
            zztop = StringInsert(buffer, (void *)ptr->name, ptr->name);
            
            ptr = ptr->next;
            
        }
        
        ptr = buffer->head;
    }
    
    
    /*For printing*/
    ptr = buffer->head;
/*    printf("%s", ptr->name);
    ptr = ptr->next;
    while (ptr!=NULL) {
        printf("->%s ", ptr->name);
        ptr = ptr->next;
    }
    printf("\n");
 */


printf("\n");
	while(ptr!=NULL)
	{
		printf("\t%s\n",ptr->name);
		ptr = ptr->next;
	}
printf("\n");









   
    return 0;
}
