#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

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
        // exit(1);

        // Stretch Goal
        exit(2);
    }

    // Repeatly read and print entries
    struct dirent *entry;

    while ((entry = readdir(d)) != NULL)
    {
        // printf("%s\n", entry->d_name);

        // Stretch Goal
        // stat the entry
        char fullpath[8192];
        snprintf(fullpath, sizeof(fullpath), "%s/%s", dirname, entry->d_name);
        struct stat stat_buf;

        if (stat(fullpath, &stat_buf) < 0)
        {
            fprintf(stderr, "lsls: failed to stat file %s\n", fullpath);
            exit(3);
        }

        if (S_ISREG(stat_buf.st_mode))
        {
            printf("%10lld %s\n", stat_buf.st_size, entry->d_name);
        }
        else if (S_ISDIR(stat_buf.st_mode))
        {
            printf("%10s %s\n", "<DIR>", entry->d_name);
        }
        else
        {
            printf("%10s %s\n", "", entry->d_name);
        }
    }

    // Close directory
    closedir(d);

    return 0;
}