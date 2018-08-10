#include <stdio.h>
#include <stdlib.h>
#include <dirent.h> // let's us open a directory

/**
 * Main
 */
int main(int argc, char **argv)
{
  char *dirname;
  if (argc == 1) {
    // set the directory that we're going to be looking at to "."
  dirname = ".";
  } else if (argc == 2) {
    dirname = argv[1];
  } else {
    fprintf(stderr, "usage: lsls [dirname]\n");
    exit(1);
  }

  // Open directory
  DIR * d = opendir(dirname);

  if (d == NULL) {
    fprintf(stderr, "lsls: cannot open directory %s\n", dirname);
    exit(2);
  }

  struct dirent *entry;

  while ((entry = readdir(d)) != NULL) {
    printf("%s\n", entry->d_name);
  }

  closedir(d);

  return 0;
}

  // ***print out dictory listing user specifies on command line.
  // ***IF no directory specified then print contents of current directory

  // Parse command line
    //printf(suser pecify directory)
  // Open directory
    //opendir()
  // Repeatly read and print entries
    //readdir() return NULL when no more entries
  // Close directory
    //closedir()

  // DIR *directory = opendir(".");
  // char *result = directory == NULL ? "Did not open" : "Succeded!"; // ternary operator
  // printf("Testing opening a directory:  %s\n", result);
  // closedir(directory);