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
  char *path;
  // Parse command line
  if (argc > 2) {
    fprintf(stderr, "Usage: ./lsls <directory name>(optional)");
    exit(1);
  } else if (argc == 2) {
    path = argv[1];
  } else {
    path = ".";
  }

  // Open directory
  d = opendir(path);
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