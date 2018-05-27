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
      printf("closedir() was unsuccessful\n");
    }
    exit(0);
  }

  for (i = 1; i < argc; i++)
  {
    dir = opendir(argv[i]);
    printf("dir: %p\n", dir);

    if ((dir = opendir(argv[i])) == NULL)
    {
      printf("OPENDIR unsuccessful\n");
      exit(1);
    }

    while ((dp = readdir(dir)) != NULL)
    {
      printf("%s\n", dp->d_name);
    }

    int isClosed = closedir(dir);
    if (isClosed != 0)
    {
      printf("closedir() was unsuccessful\n");
    }
    exit(0);
  }

  return 0;
}