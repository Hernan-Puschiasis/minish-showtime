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

    struct sigaction str_sigint_action;
    memset(&str_sigint_action, 0, sizeof(str_sigint_action)); // llena con 0's la struct
    str_sigint_action.sa_handler = SIG_IGN;
    sigaction(SIGINT, &str_sigint_action, NULL); // ejecuta el sigaction, activa el manejador

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