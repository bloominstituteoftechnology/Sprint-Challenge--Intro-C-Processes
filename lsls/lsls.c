#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line

  // Open directory
  DIR *dir;
  struct dirent *dp;
  if ((dir = opendir(".")) == NULL) {
    perror("Error opening direcoty.");
    exit(1);
  }

  // Repeatly read and print entries
  while ((dp = readdir(dir)) != NULL) {
    printf("%s\n", dp->d_name);
  }

  // Close directory
  closedir(dir);

  return 0;
}