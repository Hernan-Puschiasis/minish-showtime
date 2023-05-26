#include <stdio.h>

#define MAX_LINE 1024

char line[MAX_LINE];

int main(){
    fprintf(stderr, "$ ");
    while(fgets(line, MAX_LINE, stdin) != NULL){

    }
}