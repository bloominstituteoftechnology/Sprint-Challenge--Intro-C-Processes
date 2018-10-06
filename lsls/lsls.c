#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv) // main takes in a argv pointer. Is argc number or args given?
{
  DIR *directoryName; // Store directory name in a pointer
  struct dirent *pointDir; // struct that finds serial # and Directory name

  if(argc == 1) // need to check that arg[1] is set to something
  {
    directoryName = opendir(argv[1]); // set dir to that arg index, and open it, need pointer path for Opendir

  } else { // that directory doesn't exit and can't be located

    printf("File directory does not exist.\n");

    // exit(1); do I need to exit?
  }

  // Now I need to iterate and find all directories. Do... While? Or NULL check? With while loop?
  


  return 0;
}