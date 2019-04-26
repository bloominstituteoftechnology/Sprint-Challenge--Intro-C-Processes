//
//  main.c
//  cSprint
//
//  Created by Nikita Thomas on 4/26/19.
//  Copyright © 2019 Nikita Thomas. All rights reserved.
//

#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    char *path = argv[1] != NULL ? argv[1] : ".";
    
    DIR *dir = opendir(path);
    
    struct dirent *ent;
    while ((ent = readdir(dir)) != NULL){
        char *name = ent->d_name;
        char directory[strlen(path) + strlen(name)];
        strcpy(directory, path);
        strcat(directory, "/");
        strcat(directory, name);
        
        struct stat buf;
        stat(directory, &buf);
        printf("%lld %s\n", buf.st_size, name);
    }
    
    closedir(dir);
    return 0;
}


