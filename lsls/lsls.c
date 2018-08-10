#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  struct dirent *newdir;
  DIR *d;
  // Parse command line

  // Open directory
  d = opendir(".");
  if (d == NULL) {
    fprintf(stderr, "Error Opening Directory");
    exit(1);
  }

  // Repeatly read and print entries
  while ( (newdir = readdir(d)) != NULL ) {
    printf("%s\n", newdir->d_name);
  }
  
  // Close directory
  closedir(d);

  return 0;
}