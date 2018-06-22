#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *dir;
  struct dirent *pDirent;
  // Parse command line
  if (argc < 2)
  {
    dir = opendir(".");
    argv[1] = ".";
  }
  else
  {
    dir = opendir(argv[1]);
  }
  // Open directory
  if (dir == NULL) {
    printf("The directory is empty! :(\n");
    exit(1);
  }

  // Repeatly read and print entries

  // Close directory

  return 0;
}