#include <stdio.h>
#include "wrappers.h"
#include <stdlib.h>
#include <sys/types.h>
#include <pwd.h>
#include <unistd.h>
#include "minish.h"
#include <signal.h>
#include <string.h>
#include "lista.h"

char line[MAXLINE];

char *last_path;
int globalstatret = 0;
struct builtin_struct builtin_arr[] = {
        { "cd", builtin_cd, HELP_CD },
        { "dir", builtin_dir, HELP_DIR },
        { "exit", builtin_exit, HELP_EXIT },
        { "help", builtin_help, HELP_HELP },
        { "history", builtin_history, HELP_HISTORY },
        { "getenv", builtin_getenv, HELP_GETENV },
        { "pid", builtin_pid, HELP_PID },
        { "setenv", builtin_setenv, HELP_SETENV },
        { "status", builtin_status, HELP_STATUS },
        { "uid", builtin_uid, HELP_UID },
        { "unsetenv", builtin_unsetenv, HELP_UNSETENV},
        { "gid", builtin_gid, HELP_GID},
        { NULL, NULL, NULL }
    };

struct list *history_list;
char *history_file_path;

int main(){
    history_list = list_create();
    last_path = getenv("PWD");

    //Consigue path para abrir el file del history
    char *home = getenv("HOME");
    int home_length = strlen(home);
    int file_length = strlen(HISTORY_FILE);
    history_file_path = malloc_or_exit(home_length + file_length + 1);
    strcpy(history_file_path, home);
    strcat(history_file_path, HISTORY_FILE);

    FILE *fp = fopen(history_file_path,"r");
    if(fp == NULL){
        fp = fopen(history_file_path,"a+");
    }

    //Llena la estructura con las lineas del archivo history
    while(fgets(line, MAXLINE, fp) != NULL){
        list_append(history_list, line);
    }

    fclose(fp);

    char **argv = calloc_or_exit(MAXWORDS, MAXLINE);
    int argc;
    uid_t uid = getuid();
    struct passwd *p = getpwuid(uid);
    
    //Maneja la interrupcion del CTRL-C
    struct sigaction str_sigint_action;
    memset(&str_sigint_action, 0, sizeof(str_sigint_action)); // llena con 0's la struct
    str_sigint_action.sa_handler = normalInterruptHandler;
    sigaction(SIGINT, &str_sigint_action, NULL); // ejecuta el sigaction, activa el manejador
    
    while(1){
    
        fprintf(stderr,  "(minish) " RED"%s" RESET ":" CYAN "%s" RESET "$ ", p -> pw_name, getenv("PWD")); 
        clearerr(stdin);
        if(fgets(line, MAXLINE, stdin) == NULL){
            if(feof(stdin)){
                break;
            }
            continue;
        }
        list_append(history_list,line);
        
        
        argc = linea2argv(line, MAXWORDS, argv);
        
        if(argc > 0){
            globalstatret = ejecutar(argc,argv);
        }   
    }

    update_history();
}