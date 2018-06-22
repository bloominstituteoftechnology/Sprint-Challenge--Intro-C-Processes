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
  // Too many arguments
  else if (argc > 2)
  {
    perror("Too many arguments");
    exit(1);
  }
  // Directory path is given
  else 
  {
    // Open target directory
    dir = opendir(argv[1]);
    // Directory not found
    if (dir == NULL) 
    {
      perror("Cannot open");
      exit(1);
    }
    // Print directory contents
    while ((dp = readdir(dir)) != NULL) 
    {
      printf ("%s\n", dp->d_name);
    }
  }

  return 0;
}