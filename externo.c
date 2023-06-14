#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "minish.h"
#include "wrappers.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>


/*
Toma como inputs argc y los comandos en argv
Ejecuta el comando externo pasado por consola y retorna el status
*/
int externo (int argc, char ** argv){
    pid_t child_pid;
    int status;

    struct sigaction str_sigint_action_old;
    struct sigaction str_sigint_action;
    
    if(argc){}
    
    child_pid = fork();
    if(child_pid == -1){
        fprintf(stderr, "Error en la ejecucion del comando externo\n");
        return 1;
    }

    //Código proceso hijo
    if(child_pid == 0){
        memset(&str_sigint_action, 0, sizeof(str_sigint_action)); // llena con 0's la struct
        str_sigint_action.sa_handler = SIG_DFL;
        sigaction(SIGINT, &str_sigint_action, NULL); // ejecuta el sigaction, activa el manejador
        execvp(argv[0], argv);
        perror("Error");
        exit(errno);       
    }

    //Código proceso padre
    memset(&str_sigint_action, 0, sizeof(str_sigint_action)); // llena con 0's la struct
    str_sigint_action.sa_handler = SIG_IGN;
    sigaction(SIGINT, &str_sigint_action, &str_sigint_action_old); // ejecuta el sigaction, activa el manejador

    //Espera a que termine el proceso hijo y vuelve a habilitar la interrupción
    child_pid = wait(&status);
    sigaction(SIGINT, &str_sigint_action_old, NULL);
    
    if(WIFEXITED(status)){
        return WEXITSTATUS(status);
    }
    fprintf(stderr, "\n");
    return WTERMSIG(status);
    
}