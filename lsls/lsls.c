#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line

  // Open directory
  struct dirent *dirent;
  DIR *dr = opendir(argv[1]);
  printf("%s", dr);
  if (dr == NULL) {
    printf("could not open current directory");
    exit(2);
  }
  // Repeatly read and print entries
  while( (dirent = readdir(dr)) != NULL)
    printf("%s\n", dirent->d_name);
  // Close directory
  closedir(dr);
  exit(1);
  return 0;
}