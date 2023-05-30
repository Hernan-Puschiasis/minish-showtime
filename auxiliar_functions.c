#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "minish.h"
#include "wrappers.h"

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