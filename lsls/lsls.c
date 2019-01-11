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

  return 0;
}