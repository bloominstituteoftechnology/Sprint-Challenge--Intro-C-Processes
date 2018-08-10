#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *dir;
  struct dirent *dp;
  char *cmdlinpt;
  // Parse command line
  cmdlinpt = "."
  if ((dir = opendir (cmdlinpt)) == NULL) {
    fprintf(stderr, "cannot open .");
    exit(1);
  } else if(argc == 2) {
    cmdlinpt = argv[1];
   } else {
     fprintf(stderr, "Incorrect usage");
     exit(1);
   }
  // Open directory
  dir = opendir(argv[1]);
  // Repeatly read and print entries

  // Close directory

  return 0;
}