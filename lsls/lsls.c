#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char *path;
  if (argc == 1) {
    path = ".";
  } else if (argc == 2) {
    path = argv[1];
  } else {
    fprintf(stderr, "Error\n");
    exit(1);
  }

  // Open directory
  DIR *dir = opendir(path);
  struct dirent *dirent;

  if (dir == NULL) {
      fprintf(stderr, "Error: NULL\n");
      exit(1);
  }

  // Repeatly read and print entries
  while ((dirent = readdir(dir))) {
    printf("%s\n", dirent->d_name);
  }

  // Close directory
  closedir(dir);

  return 0;
}