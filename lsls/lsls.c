#include <stdio.h>
#include <dirent.h>
#include <unistd.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
    DIR *curr_dir;
    struct dirent *file;
    
    // Parse command line
    if (argc == 1)
    {
        curr_dir = opendir("./");
        
        printf("Contents of current directory:\n");
        
        while ((file = readdir(curr_dir)) != NULL)
        {
            printf(" %s\n", file->d_name);
        }

        closedir(curr_dir);
    }
    else
    {
        // Open directory
        curr_dir = opendir(argv[1]);

        if (curr_dir == NULL)
        {
            printf("Directory does not exist");
        }
        else
        {
            printf("Contents of directory:\n");

            // Repeatly read and print entries
            while ((file = readdir(curr_dir)) != NULL)
            {
                printf(" %s\n", file->d_name);
            }

            // Close directory
            closedir(curr_dir);
        }
    }

    return 0;
}