#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define MAX_COMMAND_CHARS 107

/**
 * Main
 */
int main(int argc, char **argv)
{
    // Parse command line
    
    if (argc != 2 || strcmp(argv[1], "--help") == 0)
    {
        fprintf(stderr, "usage: enter a path to a directory (cannot exceed 100 characters)\n");
        exit(1);
    }

    char *path = argv[1];

    // Open directory

    DIR *dir = opendir(path);

    if (dir == NULL)
    {
        fprintf(stderr, "error: couldn't open desired directory\n");
        exit(1);
    }

    // Repeatly read and print entries

    struct dirent *direntbuff = readdir(dir);

    while (direntbuff != NULL)
    {
        char path[100];
        sprintf(path, "%s/%s", argv[1], direntbuff->d_name);
        struct stat statbuff;
        int success = stat(path, &statbuff);
        success != -1 ? printf("\t%lld", statbuff.st_size) : printf("\t");
        printf("\t%s\n", direntbuff->d_name);
        direntbuff = readdir(dir);
    }

    // Close directory

    closedir(dir);

  return 0;
}