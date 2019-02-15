#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Pointer for directory entry
  struct dirent *de;
  // Pointer
  struct stat buf;
  char *path;

  // Parse command line
  if (argv[1] != NULL)
  {
    path = argv[1];
  }
  else
  {
    path = ".";
  }

  // Open directory
  DIR *d = opendir(path);

  // Check for errors
  if (d == NULL)
  {
    printf("The directory does not exist.\n");
    exit(0);
  }

  printf("Testing path: %s\n", path);

  // Repeatly read and print entries
  while ((de = readdir(d)) != NULL)
  {
    printf("%llu %s\n", de->d_ino, de->d_name);
  }

  // Close directory
  closedir(d);

  return 0;
}