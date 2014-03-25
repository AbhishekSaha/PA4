//
//  check.c
//  
//
//  Created by Abhishek Saha on 3/23/14.
//
//

#include <stdio.h>
#include "logic.h"
#include "process.h"
#include <string.h>
#include <stdlib.h>

int main(int argc, const char **argv){
    char *s = "Sal";
    char *sal = (char*)malloc(4);
    strcpy(sal, s);
    char *f_name = "randy.txt";
    char * copytwo = malloc(strlen(f_name) +1);
    strcpy(copytwo, f_name);
    NNodePtr him = (NNodePtr)malloc(sizeof(Node));
    him->key = sal; him->filename = copytwo;
    
    insert(him);
    
    f_name = "rondy.txt";
    copytwo = malloc(strlen(f_name) +1);
    strcpy(copytwo, f_name);
    him->key = sal; him->filename = copytwo;
    insert(him);
    
    char *r = "rachel";
    char *ral = (char *)malloc(strlen(r)+1);
    strcpy(ral, r);
    f_name = "rondy.txt";
    copytwo = malloc(strlen(f_name) +1);
    strcpy(copytwo, f_name);
    him->key = ral; him->filename = copytwo;
    insert(him);
    
    
    
    
    f_name = "other.txt";
    copytwo = malloc(strlen(f_name) +1);
    strcpy(copytwo, f_name);
    him->key = ral; him->filename = copytwo;
    insert(him);
    
    
    char **lsts = (char**)malloc(sizeof(char*));
    char *saa = (char*)malloc(3);
    char rep = "sa";
    strcpy(saa, rep);
    *lsts = saa;
    *(lsts+1) = s;
    *(lsts+2) = r;
    int zz = 0;
    zz = sa(3, lsts);
    
    return 0;
    
}