#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

/**
 * Main
 */
// argc=argument count, argv=accepts a string as input
int main(int argc, char **argv)
{
  // Parse command line

  // string variable to hold the name of a directory.
  char *dirname;
  // if argc == 1, there were no arguments given because
  // argc includes the name of the program itself.
  if (argc == 1) 
  {
    // set directory we are looking at to "."
    dirname = '.';
  }
  // If argc recieves an argument
  else if (argc == 2)
  {
    // take the recieved arguement and assign the it to the Directory Name.
    dirname = argv[1];
  }
  // otherwise, we recieved something else as input
  else 
  {
    // send a standard error with an exit code.
    // I've been thinking about this code block like a standard "catch" in JS.
    fprintf(stderr, "Usage: lsls [dirname]\n");
    exit(1);
  }

  // Open directory

  // Repeatly read and print entries

  // Close directory

  return 0;
}