#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE 80
#define MAX_ARGS 10

int main(){
    char input[MAX_LINE];
    char *token;
    char *argv[MAX_ARGS];

    while(1){
        //prompt
        printf("myshell> ");

        //read command
        fgets(input, MAX_LINE,stdin);
        
        //tokenize input
        token = strtok(input, " \n");
        int i = 0;

        while(token != NULL){
            argv[i++] = token;
            token = strtok(NULL, "\n\t");
        }
        argv[i] = NULL;

        if(argv[0] == NULL){ // empty command
            continue;
        }

        if(strcmp(argv[0],"exit") == 0) {
            printf("GoodBye \n");
            exit(0);
        }

    }

    return 0;
}