#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/types.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line

  // Open directory
  DIR *dir;
  struct dirent *sd;
  dir = opendir(".");

  if (dir == NULL) {
    printf("Error, cannot open directory!\n");
    exit(1);
  }

  // Repeatly read and print entries
  while((sd = readdir(dir)) != NULL) {
    printf(">> %s\n", sd->d_name);
  }

  // Close directory
  closedir(dir);
  return 0;
}