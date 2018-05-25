#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line

  for (int i = 1; i < argc; i++)
  {
    printf("%s", argv[i]);
    return 0;
  }

  // Open directory
  DIR *dir;
  struct dirent *sd;

  dir = opendir(".");

  if (dir == NULL)
  {
    printf("Error! Unable to open directory.\n");
    exit(1);
  }

  // Repeatly read and print entries
  while ((sd = readdir(dir)) != NULL)
  {
    printf(">> %s\n", sd->d_name);
  }

  // Close directory
  closedir(dir);

  return 0;
}