#include <stdio.h>
#include <string.h>
#include "lista.h"
#include "wrappers.h"

struct list *list_create(void){
    struct list *new_list = (struct list *)malloc_or_exit(sizeof(struct list));
    new_list->count=0;
    new_list->leftmost = NULL;
    new_list->rightmost = NULL;
    return new_list;
}

struct list_elem *list_append(struct list *list, char *s){
    if(list == NULL || s == NULL){
        return NULL;
    }
    struct list_elem *new_element = (struct list_elem *)malloc_or_exit(sizeof(struct list_elem));
    new_element->str = strdup_or_exit(s);
    if(list->count==0){
        new_element->next = new_element->prev = NULL;
        list->leftmost = list->rightmost = new_element;
        list->count++;
    }else{
        new_element->prev = list->rightmost;
        new_element->next = NULL;
        list->rightmost->next = new_element;
        list->rightmost = new_element;
        list->count++;
    }
    return new_element;
}

//Funciona como lista en un solo sentido
struct list_elem *list_append_alphabetically(struct list *list, char *s){
    if(list == NULL || s == NULL){
        return NULL;
    }
    struct list_elem *new_element = (struct list_elem *)malloc_or_exit(sizeof(struct list_elem));
    new_element->str = strdup_or_exit(s);
    new_element->prev=NULL;
    if(list->count==0){
        new_element->next = NULL;
        list->leftmost = list->rightmost = new_element;
        list->count++;
    }else{
        if(strcmp(new_element->str,list->leftmost->str)<0){
            new_element -> next = list->leftmost;
            list->leftmost = new_element;
            list->count++;
        }else{
            struct list_elem *iterator;
            for(iterator=list->leftmost;iterator->next!=NULL && strcmp(new_element->str,iterator->next->str)>=0;iterator=iterator->next){
            }
            if(iterator->next==NULL){
                list->rightmost->next = new_element;
                new_element->next = NULL;
                list->rightmost = new_element;
            }else{
                new_element->next=iterator->next;
                iterator->next = new_element;
            }
            list->count++;
        }               
    }
    return new_element;
}

void list_print(struct list *list){
    if(list != NULL && list->count>0){
        struct list_elem *iteration_element = list->leftmost;
        while(iteration_element!=NULL){
            printf("%s",iteration_element->str);
            iteration_element = iteration_element->next;
        }
    }
}

void list_print_with_space(struct list *list){
    if(list != NULL && list->count>0){
        struct list_elem *iteration_element = list->leftmost;
        while(iteration_element!=NULL){
            printf("%s\n",iteration_element->str);
            iteration_element = iteration_element->next;
        }
    }
}

struct list_elem *list_pop_left(struct list *list){
    if(list == NULL || list->count==0){
        return NULL;
    }
    struct list_elem *removed_element = list->leftmost;
    list->count--;
    if((list->count) == 0){
        list->leftmost = NULL;
        list->rightmost = NULL;
    }else{
        list->leftmost = removed_element->next;
        list->leftmost->prev = NULL;
    }
    return removed_element;
}