#include <stdio.h>
#include <stdlib.h>
#include "sorted-list.h"
#include <string.h>


SortedListPtr SLCreate(CompareFuncT cf)
{
    SortedListPtr newPtr;
	newPtr = (SortedListPtr) malloc(sizeof(struct SortedList));
    
    newPtr->head = NULL;
    newPtr->compareTo = cf;
    
    /*    newPtr->SortedListIteratorPtr = NULL;*/
    
	
 	return newPtr;
}


void SLDestroy(SortedListPtr list)
{
    Node *cur = list->head;
    
    while(cur != NULL)
    {
        list->head = list->head->next; /*Move the head forward*/
        cur->next = NULL; /*Disconnect cur*/
        NodeDestroy(cur); /*Destroy the disconnected node*/
        cur = list->head; /*point cur to the new head*/
    }
    
    free(list);
    
	
    return;
}

NodePtr NodeCreate(void *newObj, char*name)
{
    
	NodePtr newPtr = (NodePtr) malloc(sizeof(Node));
    
    newPtr->name = name;
	newPtr->data = newObj;
	newPtr->next = NULL;
	newPtr->refcount = 0;
    
	
    
	return newPtr;
}

void NodeDestroy(NodePtr myNode)
{
    free(myNode->name);
    free(myNode->data);
	free(myNode);
	
    
	return;
}




/* Inserts given object into the list while maintaining sorted order. Success returns 1,
 failure returns 0 */

int SLInsert(SortedListPtr list, void *newObj, char*key)
{
	if(list->head == NULL)
	{
		NodePtr newNode = NodeCreate(newObj, key);
		list->head = newNode;
		list->head->refcount += 1;
		
        
        
		return 1;
	}
	else if(list->head != NULL)
	{
        
        
		NodePtr cur = list->head;
		NodePtr prev = NULL;
        int comp = 0;
        comp = (int)strcmp(cur->name, key);
        while (cur->next!=NULL && comp!=0) {
            prev = cur;
            cur = cur->next;
            printf("Entered: %s\n", prev->name);
            if(cur->name==NULL){
                comp = -1;  break;}
            comp = (int)strcmp(cur->name, key);
            
        }
        
        if (comp==0) {
            int * y = (int*) malloc(sizeof(int));
            *y = *((int*)cur->data) + 1;
            
            
            
            cur->data  = (void*)y;
            
          //  printf("Before insert, the filname is:%s\n", key);
            if(prev==NULL){
                list->head = list->head->next;}
            else{
                prev->next = cur->next;
                cur->next = NULL;}
            Insert(list, (void*) y , key);
            cur = list->head;
            return 1;
        }
        else{
            
            NodePtr nu = NodeCreate(newObj, key);
            printf("cur: %s\n", cur->name);
            if(cur->name==NULL){
                cur = NULL; prev->next = NULL;};
            printf("Before insert, the filname is:%s\n", key);
            Insert(list, newObj, key);
        }
        
        
    }
    
    return 1;
}


int Insert(SortedListPtr list, void *newObj, char*key){
    if(list->head==NULL)
    {
        
        NodePtr newNode = NodeCreate(newObj, key);
        list->head = newNode;
        list->head->refcount += 1;
        
        
        
        
        
        
        return 1;
    }
    else
    {
        
        
        NodePtr cur = (NodePtr)malloc(sizeof(Node));
        cur = list->head;
        
        
        NodePtr prev = NULL;
        
        
        /*Move the cur and prev pointers until cur points to the node where the newObj
         should be inserted and prev points to the node before that point. */
        
        CompareFuncT comp  = list->compareTo;
        int aa = comp(newObj, cur->data);
        if(aa < 0)
        {
            
            
            NodePtr newNode = NodeCreate(newObj, key);
            
            newNode->next = cur;
            
            list->head = newNode;
            newNode->refcount += 1;
            
            
            
            
            return 1;
        }
        else
        {
            
            while((cur != NULL) && (list->compareTo(newObj,cur->data)) >= 0)
            {
                if(newObj == cur->data)
                {
                    
                    return 1;
                }
                prev = cur;
                cur = cur->next;
            }
            
            
            NodePtr newNode = NodeCreate(newObj, key);
            /*Insert*/
            
            
            prev->next = newNode;
            
            newNode->refcount += 1;
            
            newNode->next = cur;
            
            
            
            return 1;
        }
    }
}


int StringInsert(SortedListPtr list, void *newObj, char*key){
    if(list->head==NULL)
    {
        NodePtr newNode = NodeCreate(newObj, key);
        
        list->head = newNode;
        
        
        
        
        
        return 1;
    }
    else
    {
        
        
        NodePtr cur = (NodePtr)malloc(sizeof(Node));
        cur = list->head;
        
        
        NodePtr prev = NULL;
        
        
        /*Move the cur and prev pointers until cur points to the node where the newObj
         should be inserted and prev points to the node before that point. */
        
        CompareFuncT comp  = list->compareTo;
        int aa = strcmp(key, cur->name);
        if(aa < 0)
        {
            
            
            NodePtr newNode = NodeCreate(newObj, key);
            
            newNode->next = cur;
            
            list->head = newNode;
            newNode->refcount += 1;
            
            
            
            
            return 1;
        }
        else
        {
            
            while((cur != NULL) && (list->compareTo(newObj,cur->data)) >= 0)
            {
                if(list->compareTo((void*)cur->name, (void*) key)==0)
                {
                    
                    return 1;
                }
                prev = cur;
                cur = cur->next;
            }
            
            
            NodePtr newNode = NodeCreate(newObj, key);
            /*Insert*/
            
            
            prev->next = newNode;
            
            newNode->refcount += 1;
            
            newNode->next = cur;
            
            
            
            return 1;
        }
    }
}






int SLRemove(SortedListPtr list, char * key)
{
	
    
	if(list->head==NULL)
	{
		
		return 0; // remove failed
	}
	else
	{
        
		NodePtr cur = list->head;
		NodePtr prev = NULL;
        int comp = strcmp(cur->name, key);
		while (cur->next!=NULL && comp!=0) {
            cur = cur->next;
            prev = cur;
            comp = (int)strcmp(cur->name, key);
        }
        
		if ((int)strcmp(cur->name, key)==0 && prev!=NULL) {
            
            prev->next = cur->next;
            
            NodeDestroy(cur);
        }
        else if(prev==NULL){
            cur->next = NULL;
            list->head = NULL;
            
            NodeDestroy(cur);
        }
        else{
            
        }
    }
    return 1;
}


SortedListIteratorPtr SLCreateIterator(SortedListPtr list)
{
	
    
	SortedListIteratorPtr  init = (SortedListIteratorPtr) malloc(sizeof(SortedListIterator));
    
	init->current = list->head;
    
	if(init->current != NULL)
		init->current->refcount += 1;
    
	
	
	return init;
}


void SLDestroyIterator(SortedListIteratorPtr iter)
{
	
	iter->current->refcount -= 1;
	iter->current = NULL;
	free(iter);
	
	return;
}



void *SNextItem(SortedListIteratorPtr iter)
{
	
	if (iter->current->next==NULL)
    {
		void *temp = iter->current->data;
		iter->current = iter->current->next;
		
        
		return temp;
   	}
	void *temp = iter->current->data;
    
	iter->current->refcount -= 1;
    
	if(iter->current->refcount==0)
	{
		
		NodePtr tomp = iter->current;
        
		iter->current = iter->current->next;
		iter->current->refcount += 1;
		tomp->next = NULL;
		NodeDestroy(tomp);
		
		return temp;
	}
    
	else if(iter->current->refcount >= 1)
	{
		
        
		iter->current = iter->current->next; // Move to the next node
		iter->current->refcount += 1;
		
		
		return temp;
	}
    return NULL;
}





