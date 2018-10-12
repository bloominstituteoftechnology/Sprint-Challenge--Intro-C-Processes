#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  DIR *dir;

  // Open directory
  dir = opendir(".");

  if (dir == NULL)
  {
    printf("Error! Cant open directory. \n");
    exit(1);
  }

  // Repeatly read and print entries

  // Close directory
  closedir(dir);

  return 0;
}