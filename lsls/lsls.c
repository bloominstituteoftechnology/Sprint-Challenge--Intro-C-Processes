#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char *path;
  // Check for empty command line
  if (argc > 1) {
    path = argv[1];
  } else {
    path = ".";
  } 

  // Open directory
  DIR *directory = opendir(path);
  // Check if directory could not be opened.
  if (directory == NULL) {
    printf("Directory could not be opened: %s\n", path);
    exit(1);
  }

  // Repeatly read and print entries

  // Close directory

  return 0;
}