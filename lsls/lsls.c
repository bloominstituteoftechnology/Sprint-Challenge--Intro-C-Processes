#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/types.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  printf("Is this working?\n");

  DIR *dir;
  dir = opendir(".");
  struct dirent *dp;

  if(dir == NULL)
  {
    fprintf(stderr, "ERROR Failed to open DIR");
    exit(1);
  }


  while((dp=readdir(dir)) != NULL) 
  {
    printf(">> %s\n", dp->d_name);
  }




  closedir(dir);

  // Parse command line

  // Open directory

  // Repeatly read and print entries

  // Close directory

  return 0;
}