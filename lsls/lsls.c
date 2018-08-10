#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  int count = argc;
  
  // Open directory
  DIR *dir;
  struct dirent *sd;

  dir = opendir(argv[1]);

  if(dir == NULL) {
    dir = opendir(".");
  }
 

  // Repeatly read and print entries

  while( (sd=readdir(dir)) != NULL ) {
    printf("%s \n", sd->d_name);
  }

  // Close directory

  closedir(dir);

  return 0;
}