#include "ls_command.h"
#include <dirent.h>
#include <sys/types.h>

void my_ls(void){
    DIR *dir;
    struct dirent *entry;

    dir = opendir(".");
    if(dir == NULL){
        perror("opendir");
        return;
    }
    else{
        while ((entry = readdir(dir)) != NULL){
            if(entry->d_type == DT_DIR){
                printf("%s\n", entry->d_name);
            }else{
                printf("%s\n", entry->d_name);
            }
            
        }
    }
    closedir(dir);
}

