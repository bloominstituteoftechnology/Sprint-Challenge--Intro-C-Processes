#include <stdio.h>
#include <dirent.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
    char commandline;
    DIR *directory;
    struct dirent *read_directory; 

    // Parse command line
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

        // Open directory
        //The opendir() function shall open a directory stream corresponding to the directory named by the dirname argument. 
        directory = opendir(&commandline); //Upon successful completion, opendir() shall return a pointer to an object of type DIR. Otherwise, a null pointer shall be returned 
        if(directory == NULL)
        {
            printf("Unable to open directory.\n");
            exit(0); 
        }

        //..The readdir() function returns a pointer to a structure representing the directory entry 
        //  at the current position in the directory stream specified by the argument dirp, 
        //  and positions the directory stream at the next entry. 
        //..It returns a null pointer upon reaching the end of the directory stream.
        readdir(directory);

        //Upon successful completion, readdir() returns a pointer to an object of type struct dirent.
        // Repeatly read and print entries
        while((read_directory = readdir(directory)) != NULL)
        {
            printf(">> %s  %ld\n", read_directory->d_name, read_directory->d_ino);
        }
      
        // Close directory
        closedir(directory); 

    }
    return 0;
}