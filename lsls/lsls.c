#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>


/**
 * Main
 */
int main(int argc, char **argv)
{
  char *name;
  // Parse command line
  if (argc > 1) {
    name = strdup(argv[1]);
  }
  else {
    name = ".";
  }
  // Open directory
  DIR *dir;
  struct dirent *sd;
  dir = opendir(name);

  if (dir == NULL)
  {
    printf("Unable to open the directory.");
    exit(1);
  }
  

  // Repeatly read and print entries
  while( (sd=readdir(dir)) != NULL )
    {
      printf("%s\n", sd->d_name);
    }
  // Close directory

  return 0;
}