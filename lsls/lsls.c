#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

#define MAX_COMMAND_CHARS 50

/**
 * Main
 */
int main(int argc, char **argv)
{
    // Parse command line
    
    if (argc != 2)
    {
        fprintf(stderr, "usage: enter a path to a directory\n(spaces are not permitted)\n");
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
        printf("%s\n", direntbuff->d_name);
        direntbuff = readdir(dir);
    }

    // Close directory

    closedir(dir);

  return 0;
}