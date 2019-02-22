#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  /* check to make sure that proper arguments are being passed on the command line */

  struct dirent *Directory;
  DIR *dir;

  if(dir == NULL) {
    fprintf(stderr, "Please provide a directory!\n"); /* error handling for non-argument cases */
  }
  else if(argc < 2) {
    dir = opendir(".");
  }
  else {
    dir = open(argv[1]);
  }
  // Open directory

  // Repeatly read and print entries

  // Close directory

  return 0;
}