#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *d;
  struct dirent *ent;

  // Parse command line
  if (argc == 1) {
    d = opendir(".");
  }
  else if (argc == 2) {
    d = opendir(argv[1]);
  }
  else {
    fprintf(stderr, "Supply a single path to ls\n");
  }

  // Open directory
  if (d == NULL) {
    fprintf(stderr, "Something went horribly wrong\n");
    exit(1);
  }
  else {
  // Repeatly read and print entries
    ent = readdir(d);
    while (ent != NULL) {
      printf("%s\n", ent->d_name);
      ent = readdir(d);
    }
  }
  // Close directory
  closedir(d);
  return 0;
}