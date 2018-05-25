#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *dir;
  struct dirent *dp;
  char *filename = ".";

  // Parse command line
  if (argc == 2)
  {
    filename = argv[1];
  }
  else if (argc > 2)
  {
    fprintf(stderr, "You can only list the contents of one directory at a time.\n");
  }

  // Open directory
  if ((dir = opendir(filename)) == NULL)
  {
    fprintf(stderr, "Cannot Open .");
    exit(1);
  }

  // Repeatly read and print entries

  ;

  while ((dp = readdir(dir)) != NULL)
  {
    printf("%s\n", dp->d_name);
  }

  // Close directory

  return 0;
}