#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *dir;
  struct dirent *pDirent;

  // Parse command line
  if (argc < 2) // Default current dir
  {
    dir = opendir(".");
    argv[1] = ".";
  }
  else
  {
    dir = opendir(argv[1]); // dir path
  }
  // Open directory
  if (dir == NULL)
  {
    printf("The directory is empty! :(\n"); // test ./lsls x
    exit(1);
  }
  // Repeatly read and print entries
  else
  {
    while ((pDirent = readdir(dir)) != NULL) // read while dir not empty
    {
      printf("%s\n", (*pDirent).d_name);
    }
  }

  // Close directory
  closedir(dir);

  return 0;
}