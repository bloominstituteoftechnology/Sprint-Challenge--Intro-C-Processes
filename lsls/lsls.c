#include <stdio.h>
#include <dirent.h>
#include <dirent.h>


/**
 * Main
 */
int main(int argc, char **argv)
{
    char commandline;
    DIR *directory;

    // Parse command line

    // Open directory

    // Repeatly read and print entries

    // Close directory
    while (strcmp(&commandline, "exit")!= 0)
    {
        // Receive input from stdin
        // shell should print a prompt for the user
        printf("lambda-shell(Enter exit to exit)$");
        scanf("%s", &commandline);

        if (strcmp(&commandline, "exit") == 0)
        {
            printf("exiting\n"); 
            exit(0); 
        }


    }
    return 0;
}