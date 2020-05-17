#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define LINE_READ_ERROR "An error occurred while reading the line\n"




char* readline(void){

    unsigned int buffsize = 1024;
    int pos = 0;
    char* buffer = (char*)malloc(sizeof(char) * buffsize);
    int c;

    if(!buffer){
        fprintf(stderr, LINE_READ_ERROR);
        exit(1);
    }

    while(1){
        c = getchar();

        if(c == EOF || c == '\n'){
            buffer[pos] = '0';
            return buffer;
        } else {
            buffer[pos] = c;
        }
        pos++;

        if(pos >= buffsize){
            buffsize += 256;
            buffer = (char*)realloc(buffer, buffsize);
            if(!buffer){
                fprintf(stderr, LINE_READ_ERROR);
                exit(1);
            }
        }
    }
}

