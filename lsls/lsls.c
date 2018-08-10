#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char *dirname;

  if (argc == 1) {
    dirname = ".";
  } else if (argc == 2)  {
    dirname = argv[1];
  } else {
    fprintf(stderr, "You must provide a valid directory name.\n");
    exit(1);
  }
  // Open directory
  DIR *directory;
  struct dirent *dir;
  directory = opendir(".");

  if (directory == NULL) {
    fprintf(stderr, "The given directory %s cannot be opened.", dirname);
    exit(1);
  }

  // Repeatly read and print entries
  
  while ((dir = readdir(directory)) != NULL) {
    printf("Open directory: %s\n", dir->d_name);
  }

  // Close directory
  closedir(directory);
  return 0;
}