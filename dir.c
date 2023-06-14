#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <dirent.h>
#include "wrappers.h"
#include "minish.h"
#include "lista.h"

/*Funcion auxiliar: Libera la lista pasada como argumento.
A su vez tambien libera a todos sus elementos incluido los contenidos.
*/
void free_list(struct list *list){
    struct list_elem *elem;
    while( (elem = list -> leftmost) != NULL){
        elem = list_pop_left(list);
        free(elem->str);
        free(elem);
    }
    free(list);
}

/*
Muestra la lista de archivos del directorio corriente en caso de no tener ningun parametro.
Si el comando posee un parametro y se trata de un directorio (relativo o absoluto) lista los archivos del mismo.
Si este primer parametro NO es un directorio lista los archivos que contengan esa palabra en el dir corriente.
En caso de tener dos argumentos, el primero se trata de un directorio, si no existe se devuelve error.
Se listan los archivos de este directorio (primer parametro) que contengan la palabra del segundo parametro.
Devuelve el status de la operación
*/
int builtin_dir (int argc, char ** argv){
    if(argc>3){
        fprintf(stderr,"Comando admite como maximo dos parametros\n");
        return 1;
    }
    char *dir_name=getenv("PWD");
    if(argc>1){
        dir_name = argv[1];
    }
    struct list *files_names = list_create();
    DIR *directory = opendir(dir_name);
    struct dirent *dir;
    if(directory==NULL){
        if(argc!=2){
            perror("Error: ");
            return 1;
        }
        directory = opendir(getenv("PWD"));
        while((dir = readdir(directory)) != NULL){
            if(strstr(dir->d_name,argv[1])!=NULL){
                list_append_alphabetically(files_names,dir->d_name);
            }
        }
        list_print_with_space(files_names);
        free_list(files_names);
        closedir(directory);
        return 0;
    }
    if(argc<3){
        while((dir = readdir(directory)) != NULL){
            list_append_alphabetically(files_names,dir->d_name);
        }
    }else{
        while((dir = readdir(directory)) != NULL){
            if(strstr(dir->d_name,argv[2])!=NULL){
                list_append_alphabetically(files_names,dir->d_name);
            }
        }
    }
    list_print_with_space(files_names);
    free_list(files_names);
    closedir(directory);
    return 0;
}