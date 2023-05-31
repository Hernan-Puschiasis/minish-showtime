#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "minish.h"
#include "wrappers.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int externo (int argc, char ** argv){
    pid_t child_pid;
    int status;

    child_pid = fork();
    if(child_pid == -1){
        fprintf(stderr, "Error en la ejecucion del comando externo\n");
        return 1;
    }
    if(child_pid == 0){
        int child_status = execvp(argv[0], argv);
        fprintf(stderr, "Error en la ejecucion del comando externo\n");
        exit(1);       
    }

    child_pid = wait(&status);
    return WEXITSTATUS(status);
}