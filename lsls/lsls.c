#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *dir;
  struct dirent *dp;
  
  // No additional arguments
  if (argc < 2)
  {
    // Open current directory
    dir = opendir(".");
    // Print directory contents
    while ((dp = readdir(dir)) != NULL) 
    {
      printf ("%s\n", dp->d_name);
    }
  }

  return 0;
}