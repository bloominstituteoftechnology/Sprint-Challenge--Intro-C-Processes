#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  struct dirent *ent;
  // Open directory
  DIR *dir = opendir(".");
  
  if (dir == NULL )
  {
    printf("Could not open current directory");
    return 0;
  }

  // Repeatly read and print entries
  

  // Close directory
  closedir(dir);
  return 0;
}