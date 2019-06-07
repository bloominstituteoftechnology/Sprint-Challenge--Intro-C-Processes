#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>


/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char *path;
  if (argc > 1) {
    path = argv[1];
  } else {
    path = ".";
  }
  // Open directory
  struct directory *d;
  DIR *directory = opendir(path);
  if (directory == NULL) {
    printf("%s is not a valid directory\n", path);
    exit(0);
  }
  
  // Repeatly read and print entries

  // Close directory

  return 0;
}