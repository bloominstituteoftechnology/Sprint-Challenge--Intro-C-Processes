#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  // use opendir() system call
  for (int i = 0; i < argc; i++) {
    printf("%s\n", argv[i]);
  }
  char *dirname;

  if (argc == 1) {
    dirname = ".";
  } else if (argc == 2) {
    dirname = argv[1];
  } else {
    fprintf(stderr, "usage: ./lsls [dirname]\n");
    exit(1);
  }
  // Open directory
  DIR *d = opendir(dirname);
  if (d == NULL) {
    fprintf(stderr, "cannot open directory: %\n", dirname);
    exit(2);
  }

  // Repeatly read and print entries

  // Close directory

  return 0;
}