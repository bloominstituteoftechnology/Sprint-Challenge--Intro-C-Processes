#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h> //for the stat() call

/**
 * Main
 */
int main(int argc, char **argv)//argv to process commend-line arguments
//two predefined variables - the count of the command-line arguments in argc 
//and the individual arguments as character strings in the pointer array argv
{
  
  struct dirent *pDirent;//Reads the next directory entry from the DIR* returned by opendir()
  DIR *pDir;//way to use the opendir function
  struct stat sizebuf;
  // Parse command line
  if (argc < 2) {
    printf("Usage: ./lsls directory");
    exit(1);//using exit() function
  }

  // Open directory
  pDir = opendir(argv[1]);// opens the directory and returns a pointer to a variable of type DIR that will be used later. 
  if (pDir == NULL) { //If there is an error, opendir() returns NULL.
    printf("Cannot open directory '%s'\n", argv[1]);// The individual values of the parameters may be accessed with argv[1]
    exit(1); //using exit() function
  }

  return 0;
}