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
  if (argc > 1)
  {
    path = argv[1];
  }
  else
  {
    path = ".";
  }

  // Open directory

  // Repeatly read and print entries

  // Close directory

  return 0;
}