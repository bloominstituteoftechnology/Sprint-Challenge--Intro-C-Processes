#include <stdio.h>
#include <dirent.h>

// opendir()

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *dir;
  struct dirent *dp;
  int dfd, ffd;

  // Parse command line

  // Open directory
  if ((dir = opendir(".")) == NULL)
  {
    printf(stderr, "Cannot open dir\n");
    exit(1);
  }

  // Repeatly read and print entries

  // Close directory

  return 0;
}