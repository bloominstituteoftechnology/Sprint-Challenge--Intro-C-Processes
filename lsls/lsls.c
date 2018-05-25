#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv) {

  struct dirent *direntP;
  DIR *dir;
  dir = opendir(".");

  // Parse command line ???

  // Open directory, opendir()
  if (dir == NULL) {
    
    fprintf(stderr, "unable to open directory, exiting\n";
    exit(1);
  }

  // Repeatly read and print entries, readdir()
  while ((direntP = readdir(dir)) != NULL) {
    printf("%s\n", direntP->d_name, argv);
  }

  // Close directory, closedir()
  closedir(dir);

  return 0;
}