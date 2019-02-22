#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  int i;

  // printf("There are %d command line argument(s):\n", argc);

  for (i = 0; i < argc; i++)
  {
    // printf("   %s\n", argv[i]);
    printf("Directory to visit: %s\n", argv[1]);
  }

  DIR *d;
  struct dirent *dir;
  d = opendir(".");
  if (d)
  {
    while ((dir = readdir(d)) != NULL)
    {
      printf("%s\n", dir->d_name);
    }
    closedir(d);
  }
  return (0);
}