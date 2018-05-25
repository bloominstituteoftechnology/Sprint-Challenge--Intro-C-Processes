#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  // if (argc == 0) {
  //   char cl[] = ".";
  // }

  // Open directory
  DIR *d = opendir(".");
  if (d == NULL) {
    fprintf(stderr, "Bomb detonated\n");
    exit(1);
  }
  else {
  // Repeatly read and print entries
    struct dirent *ent = readdir(d);
    while (ent != NULL) {
      printf("%s\n", ent->d_name);
      ent = readdir(d);
    }
  }
  // Close directory
  closedir(d);
  return 0;
}