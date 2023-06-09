#include <stdio.h>
#include <stdlib.h>
#include "wrappers.h"
#include "minish.h"
#include "lista.h"

#define DFL_N 10

void print_last_N_elements(int cant_elements){
    struct list_elem *first_element;
    if(cant_elements>=(history_list->count)){
        first_element=history_list->leftmost;
    }else{
        first_element = history_list->rightmost;
        for(int i=0;i<(cant_elements-1);i++){
            first_element = first_element->prev;
        }
    }
    for(;first_element!=NULL;first_element=first_element->next){
        fprintf(stdout,"%s",first_element->str);
    }
}

int builtin_history (int argc, char ** argv){
    if(argc>2){
        fprintf(stderr,"Este comando admite como maximo un parametro\n");
        return 1;
    }
    if(argc==1){
        print_last_N_elements(DFL_N);
    }else{
        char *fail_convert;
        int n = strtol(argv[1],&fail_convert,10);
        if(*fail_convert){
            fprintf(stderr,"Parametro NO valido\n");
            return 1;
        }
        print_last_N_elements(n);
    }
    return 0;
}