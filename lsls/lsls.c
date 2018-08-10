#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  DIR *dir;
  struct dirent *dp;
  char *file = ".";
  if(argc == 2){
    file = argv[1];
  } else if(argc > 2){
    fprintf(stderr, "Only 1 directory can be shown at a time.\n");
  }

  // Display each command-line argument.

  // Open directory
  if((dir = opendir(file)) == NULL){
    printf (stderr, "Error, can't open directory!\n");
    exit(1);
  }
  // Repeatly read and print entries
  while((dp = readdir(dir)) != NULL){
  printf ("%s\n", dp->d_name);
  }
  // Close directory
  closedir(dir);
  return 0;
}