#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{

  DIR *dir = opendir(".");
  struct dirent *d;

  if (dir == NULL)
  {
    printf("Could not open directory?");

    return 0;
  }
  if (dir != NULL)
  {
    while ((d = readdir(dir)) != NULL)
    {
      printf(" %s\n", d->d_name);
    }
    closedir(dir);
  }

  // Parse command line

  // Open directory

  // Repeatly read and print entries

  // Close directory

  return 0;
}