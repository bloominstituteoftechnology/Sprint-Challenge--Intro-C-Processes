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
  char *path;

  // Open directory
  DIR *target = opendir(path);
 
 if (target == NULL){
   printf("%s\n", "Unable to open current directory");
   exit(1);
}
  // Repeatly read and print entries

  // Close directory

  return 0;
}