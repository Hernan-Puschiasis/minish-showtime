#include <stdio.h>
#include "wrappers.h"
#include <stdlib.h>
#include <sys/types.h>
#include <pwd.h>
#include <unistd.h>
#include "minish.h"
#include <signal.h>
#include <string.h>

char line[MAXLINE];

char *last_path;
int globalstatret = 0;
struct builtin_struct builtin_arr[] = {
        { "cd", builtin_cd, HELP_CD },
        { "dir", builtin_help, HELP_DIR },
        { "exit", builtin_exit, HELP_EXIT },
        { "help", builtin_help, HELP_HELP },
        { "history", builtin_help, HELP_HISTORY },
        { "getenv", builtin_getenv, HELP_GETENV },
        { "pid", builtin_pid, HELP_PID },
        { "setenv", builtin_setenv, HELP_SETENV },
        { "status", builtin_status, HELP_STATUS },
        { "uid", builtin_uid, HELP_UID },
        { "unsetenv", builtin_unsetenv, HELP_UNSETENV},
        { "gid", builtin_gid, HELP_GID},
        { NULL, NULL, NULL }
    };

int main(){
    last_path = getenv("PWD");
    char **argv = calloc_or_exit(MAXWORDS, MAXLINE);
    int argc;
    uid_t uid = getuid();
    struct passwd *p = getpwuid(uid);
    
    struct sigaction str_sigint_action;
    memset(&str_sigint_action, 0, sizeof(str_sigint_action)); // llena con 0's la struct
    str_sigint_action.sa_handler = normalInterruptHandler;
    
    
    while(1){
        sigaction(SIGINT, &str_sigint_action, NULL); // ejecuta el sigaction, activa el manejador
        
        fprintf(stderr,  "(minish) " RED"%s" RESET ":" CYAN "%s" RESET "$ ", p -> pw_name, getenv("PWD")); 
        clearerr(stdin);
        if(fgets(line, MAXLINE, stdin) == NULL){
            if(feof(stdin)){
                break;
            }
            continue;
        }
        
        
        argc = linea2argv(line, MAXWORDS, argv);
        
        if(argc > 0){
            globalstatret = ejecutar(argc,argv);
        }
        
        
        //Se libera el contenido de argv
        for(int i = 0; i < argc; i++){
            free(argv[i]);
        }
    }
}