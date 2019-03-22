#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
    // Parse command line
    char *path = ".";
    int ARG_POS_PATH = 1;
    if(argc > ARG_POS_PATH)
    {
        path = argv[ARG_POS_PATH];
        fprintf(stdout, "%s\n", path);
    }
    // Open directory
    DIR * directory_file = opendir(path);
    fprintf(stdout, "%d, %p\n", argc, directory_file);
    // Handle errors opening directory
    if(directory_file == NULL)
    {
        fprintf(stdout, "Error opening directory: %s\n", path);
        exit(1);
    }
    struct dirent * current_directory;
    // Repeatly read and print entries
    while(1)
    {
        current_directory = readdir(directory_file);
        if(current_directory == NULL)
        {
            break;
        }
        fprintf(stdout, "%s\n", current_directory->d_name);
    }
    // Close directory
    closedir(directory_file);
    return 0;
}