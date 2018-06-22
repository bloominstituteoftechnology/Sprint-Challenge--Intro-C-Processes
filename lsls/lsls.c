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
  struct dirent *ent;

  // Open directory
  //checks if a directory has been passed
  if (dir == NULL)
  {
    printf("Could not open directory \n");
  }

  // Repeatly read and print entries

  while ((ent = readdir(dir)) != NULL)
  {
    printf("%s\n", ent->d_name);
  }

  // Close directory

  closedir(dir);

  return 0;
}