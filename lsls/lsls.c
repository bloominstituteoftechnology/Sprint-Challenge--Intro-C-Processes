#include <stdio.h>  // install the necessary libraries
#include <stdlib.h> // to call the exit function
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char *dir_name; // initialize the directory
  if (argc == 1) {  // no argument/path was received; argc default is 1
    dir_name = "."; // set the directory to "."
  } else if (argc == 2) { // if an argument/path was received (bec argc > default 1)
    dir_name = argv[1]; // set the directory to 1 which is the path; 0 is assigned for the lsls path
  } else {
    fprintf(stderr, "There is an error. Use this format: lsls [directory_name]\n"); // in case of error, print this error message
    exit(1);  // exit with code 1
  }

  // Open directory

  // Repeatly read and print entries

  // Close directory

  return 0;
}