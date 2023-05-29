#include <stdio.h>
#include <string.h>
#include "minish.h"
#include "wrappers.h"

//Funcion que para cada linea obtenida en el shell
//devuelve la cantidad de palabras de la linea (argc)
//y las guarda en argv

int linea2argv(char *linea, int argc, char **argv){
    
    if(*linea == '\n'){
        return 0;
    }
    
    char *current_word = malloc_or_exit(MAXLINE + 1);
    int word_count = 0;
    int letter_count = 0;
    int in_word = 1;

    //Determina si se empieza con una palabra o espacio
    if(linea[0] == ' ' || linea[0] == '\t'){
        in_word = 0;
    }

    //Se itera dentro de la linea para dividirla en palabras y guardar en argv
    for(char c = *linea; (c != '\n') && word_count < argc; c = *(++linea)){
        if(in_word){
            if(c == ' ' || c == '\t'){
                current_word[letter_count] = '\0';
                letter_count = 0;
                in_word = 0;
                argv[word_count++] = strdup_or_exit(current_word);
            }
            else{
                current_word[letter_count++] = c;
            }
        }
        else{
            if(c != ' ' && c != '\t'){
                in_word = 1;
                current_word[letter_count++] = c;
            }

        }
    }

    //Guarda la ultima palabra
    if(in_word){
        current_word[letter_count] = '\0';
        argv[word_count++] = strdup_or_exit(current_word);
    }

    argv[word_count] = NULL;

    return word_count;

}