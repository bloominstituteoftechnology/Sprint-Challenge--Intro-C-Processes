#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

/**
 * Main
 */

int main(int argc, char **argv)
{
  // Parse command line
  if (argc > 2) {
    fprintf(stderr, "usage: lsls <optional: path>\n");
    exit(1);
  }

  char *path_to;

  if (argv[1]) {
    path_to = argv[1];
  } 
  else {
    path_to = ".";
  }

  // Open directory
  DIR *opened_dir = opendir(path_to);

  if (!opened_dir) {
    fprintf(stderr, "Path could not be found.\n");
    exit(1);
  }
  // Repeatly read and print entries
  struct dirent *currdir = readdir(opened_dir);

  while (currdir) {
    printf("%s\n", currdir->d_name);
    currdir = readdir(opened_dir);
  }

  // Close directory
  closedir(opened_dir);

  return 0;
}