#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char *dirname;
  if (argc == 1) {
    dirname = '.';
  } else if (argc == 2) {
    dirname = argv[1];
  } else {
    printf(stderr, "usage: lsls [dir]");
    exit(1);
  }
  // Open directory
  DIR *dirpt = opendir(dirname);
  if (dirpt == NULL) {
    printf(stderr, "Error, directory [ %s ] could not be opened", dirname);
    exit(2);
  }
  // Repeatly read and print entries
  struct dirent *entrypt;
  while ((entrypt = readdir(dirpt)) != NULL) {
    printf("%s\n", entrypt->d_name);
  }
  // Close directory
  closedir(dirpt);
  return 0;
}