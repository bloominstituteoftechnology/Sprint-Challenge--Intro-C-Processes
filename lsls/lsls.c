#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char *dirpath;

  if (argc > 1) {
    dirpath = argv[1];
  } else {
    dirpath = ".";
  } 

  // Open directory

  // Repeatly read and print entries

  // Close directory

  return 0;
}