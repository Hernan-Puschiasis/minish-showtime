#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <dirent.h>
#include "wrappers.h"
#include "minish.h"

int builtin_dir (int argc, char ** argv){
    if(argc>3){
        fprintf(stderr,"Comando admite como maximo dos parametros\n");
        return 1;
    }
    char *dir_name=getenv("PWD");
    if(argc>1){
        dir_name = argv[1];
    }
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
                fprintf(stdout, "%s\n",dir->d_name);
            }
        }
        closedir(directory);
        return 0;
    }
    if(argc<3){
        while((dir = readdir(directory)) != NULL){
            fprintf(stdout, "%s\n",dir->d_name);
        }
    }else{
        while((dir = readdir(directory)) != NULL){
            if(strstr(dir->d_name,argv[2])!=NULL){
                fprintf(stdout, "%s\n",dir->d_name);
            }
        }
    } 
    closedir(directory);
    return 0;
}