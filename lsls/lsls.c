#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  DIR *dir;
  struct dirent *sd;

  if(argc > 2)
  {
    printf("Usage: %s <directory> \n", argv[0]);
    return 0;
  }

  if (argc == 1)
  {
    dir = opendir(".");
    argv[1] = ".";
  }

  // Open directory
  if((dir = opendir(argv[1])) == NULL)
  {
    printf("Error! Unable to open directory.\n");
    exit(1);
  }

  // Repeatly read and print entries //readdir()
  while((sd=readdir(dir)) != NULL)
  {
    printf("%s \n", sd->d_name);
  }

  // Close directory
  closedir(dir);

  return 0;
}