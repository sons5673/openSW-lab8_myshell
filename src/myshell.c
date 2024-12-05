#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "ls_command.h"

#define MAX_LINE 80
#define MAX_ARGS 10
void my_ls() {
    system("ls");  // ls 명령어 실행
}

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
        } else if(strcmp(argv[0], "cd")== 0){
            chdir(argv[1]);
        }
        else if(strcmp(argv[0], "pwd") == 0){
            getcwd(input,MAX_LINE);
            printf("%s\n",input);
        }
        else if(strcmp(argv[0],"ls") == 0){
            my_ls();
        }
        else if(strcmp(argv[0],"cat") == 0){
            if(argv[1] == NULL) {
                printf("cat: missing file operand\n");
            } else {
                FILE *file = fopen(argv[1], "r");
                if (file == NULL) {
                    perror("cat");
                } else {
                    char ch;
                    while ((ch = fgetc(file)) != EOF) {
                        putchar(ch);
                    }
                    fclose(file);
                }
            }
        }else{
            if(access(argv[0], X_OK) == 0){
                printf("execute %s\n", argv[0]);
            }else{
                printf("command not found: %s\n",argv[0]);
            }
        }

    }

    return 0;
}