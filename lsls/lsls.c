#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

/**
 * Main
 */

int main(int argc, char **argv)
{
    char *dirname;
    // Parse command line
    if (argc == 1)
    {
        // set the directory that we're going to be looking at to "."
        dirname = ".";
    }
    else if (argc == 2)
    {
        dirname = argv[1];
    }
    else
    {
        fprintf(stderr, "usage: lsls [dirname]\n");
        exit(1);
    }

    // Open directory
    DIR *d = opendir(dirname);

    if (d == NULL)
    {
        fprintf(stderr, "lsls: cannot open direcotry %s\n", dirname);
        exit(1);
    }

    // Repeatly read and print entries
    struct dirent *entry;

    while ((entry = readdir(d)) != NULL)
    {
        printf("%s\n", entry->d_name);
    }

    // Close directory
    closedir(d);

    return 0;
}