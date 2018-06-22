#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

// Copied from the internet since I don't have enough time to figure out how to put two strings together correctly
void combine(char *destination, const char *path1, const char *path2)
{
    if (path1 == NULL && path2 == NULL)
    {
        strcpy(destination, "");
        ;
    }
    else if (path2 == NULL || strlen(path2) == 0)
    {
        strcpy(destination, path1);
    }
    else if (path1 == NULL || strlen(path1) == 0)
    {
        strcpy(destination, path2);
    }
    else
    {
        char directory_separator[] = "/";
        directory_separator[0] = '\\';
        const char *last_char = path1;
        while (*last_char != '\0')
            last_char++;
        int append_directory_separator = 0;
        if (strcmp(last_char, directory_separator) != 0)
        {
            append_directory_separator = 1;
        }
        strcpy(destination, path1);
        if (append_directory_separator)
            strcat(destination, directory_separator);
        strcat(destination, path2);
    }
}

int main(int argc, char **argv)
{
    int i;
    struct dirent *dp;
    char *path;
    struct stat buf;

    for (i = 0; i < argc; i++)
    {
        printf("   %s\n", argv[i]);
    }

    if (argv[1])
    {
        path = argv[1];
    }
    else
        path = ".";

    DIR *d = opendir(path);

    if (d == NULL)
    {
        fprintf(stderr, "Invalid path specified");
        return 1;
    }

    // put two readdirs first if you want to get rid of the . and .. default paths displaying every time you run this
    dp = readdir(d);
    dp = readdir(d);

    while ((dp = readdir(d)) != NULL)
    {
        char filepath[strlen(path) + strlen(dp->d_name) + 2];
        combine(filepath, path, dp->d_name);
        stat(filepath, &buf);
        printf("Filename: %s, Size: %ld bytes\n", dp->d_name, buf.st_size);
    }

    closedir(d);
    return 0;
}