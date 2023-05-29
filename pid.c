#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "minish.h"
#include "wrappers.h"

int builtin_pid (int argc, char ** argv){
    if(argc>1){
        fprintf(stderr,"Comando NO admite parametros\n");
        return 1;
    }
    if(strcmp("pid",argv[0])!=0){
        fprintf(stderr,"Error a la hora de ejecutar comando\n");
        return 1;
    }
    fprintf(stdout,"pid: %i, ppid: %i\n",getpid(),getppid());
    return 0;
}