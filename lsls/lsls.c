#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <errno.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *dir;
  struct dirent *dp;
  char *cmdlinpt;
  // Parse command line
  if(argc == 2) {
    cmdlinpt = argv[1];
  } else if(argc == 1) {
    cmdlinpt = ".";
   } else {
     fprintf(stderr, "There was an error, it must have been your fault!");
     exit(1);
   }
  // Open directory
  dir = opendir(cmdlinpt);
  // Repeatly read and print entries
  while ((dp = readdir (dir)) != NULL){
    printf("%s\n", dp->d_name);
  }

  // Close directory
  closedir(dir);

  return 0;
}