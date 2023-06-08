#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include "minish.h"
#include "wrappers.h"
#include "lista.h"

// Devuelve puntero al builtin_struct si existe comando interno, NULL en caso contrario
struct builtin_struct *take_command(char *command){
    struct builtin_struct *command_return = NULL;
    for(int i=0;builtin_arr[i].cmd != NULL;i++){
        if(strcmp(command,builtin_arr[i].cmd)==0){
            command_return = &(builtin_arr[i]);
        }
    }
    return command_return;
}

void normalInterruptHandler(int signum){
    if(signum == SIGINT){
        fprintf(stderr,"\n");
    }
}

void update_history(){
    FILE *fp = fopen(history_file_path,"w");
    //CHequear
    struct list_elem *elem = history_list -> leftmost;
    while( (elem = history_list -> leftmost) != NULL){
       elem = list_pop_left(history_list);
        fprintf(fp, "%s", elem -> str);
        free(elem);
    }
    fclose(fp); 
    free(history_list);
}  