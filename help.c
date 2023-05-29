#include <stdio.h>
#include <string.h>
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

int builtin_help (int argc, char ** argv){
    if(argc>2){
        fprintf(stderr,"Comando help solo admite un unico parametro\n\tEscribir help help para más ayuda\n");
        return 1;
    }
    if(argc==1){
        for(int i=0;builtin_arr[i].cmd != NULL;i++){
            fprintf(stdout,"%s: %s\n",builtin_arr[i].cmd,builtin_arr[i].help_txt);
        }
    }else{
        struct builtin_struct *command = take_command(argv[1]);
        if( command == NULL){
            fprintf(stderr,"Parametro no reconocido\n\tEscribir help help para más ayuda\n");
            return 1;
        }
        fprintf(stdout,"%s: %s\n",command->cmd,command->help_txt);
    }
    return 0;
}