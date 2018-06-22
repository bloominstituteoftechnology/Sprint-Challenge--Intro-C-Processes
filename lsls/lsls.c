#include <stdio.h>
#include <stdlib.h> //brought in this
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  DIR *dir;
  struct dirent *dp;
  char *filename = ".";

  if(argc == 2) {
    filename = argv[1];
  } 
  else if (argc > 2) 
    {
    fprintf(stderr, "Only contents of one directory can be shown at a time.\n");
  }

  // Open directory
  if ((dir = opendir(filename)) == NULL) {
    printf (stderr, "Error! Cannot Open Directory.\n");
    exit(1);
  }

  // Repeatly read and print entries
  while ((dp = readdir(dir)) != NULL) {
    printf ("%s\n", dp->d_name);
  }

  // Close directory
  closedir(dir);

  return 0;
}