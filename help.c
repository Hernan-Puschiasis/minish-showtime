#include <stdio.h>
#include <string.h>
#include "minish.h"
#include "wrappers.h"


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