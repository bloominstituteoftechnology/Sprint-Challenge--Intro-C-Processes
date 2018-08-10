#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *dir;
  struct stat st;
  struct dirent *dent;

  if (argc < 2)
  {
    printf("enter a directory \n");
    exit(1);
  }
  // Parse command line
  for (int i = 0; i < argc; i++)
  {
    // Open directory
    dir = opendir(argv[i]);
  }

  if (dir != NULL)
  {
    while ((dent = readdir(dir)) != NULL)
    {
      // Repeatly read and print entries
      printf("%s\n", dent->d_name);
    }
  }

  // Close directory
  closedir(dir);

  return 0;
}