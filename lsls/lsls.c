#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

/*
 * Main
*/

int main(int argc, char **argv)
{

  int i;
  DIR *dir;
  struct dirent *dp;

  printf("There are %d command line argument(s):\n", argc);

  // Parse command line
  if (!argv[1])
  {
    dir = opendir(".");

    while ((dp = readdir(dir)) != NULL)
    {
      printf("%s\n", dp->d_name);
    }
    // close dir
    int isClosed = closedir(dir);

    // verify closed
    if (isClosed != 0)
    {
      printf("closedir() was unsuccessful");
    }
    exit(0);
  }

  for (i = 0; i < argc; i++)
  {
    printf("   %s\n", argv[i]);
  }
  // Open directory

  // Repeatly read and print entries

  // Close directory

  return 0;
}