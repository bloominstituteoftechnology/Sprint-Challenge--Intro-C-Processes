#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

void ls_dir(const char *dir_name)
{
  DIR *directory;
  struct dirent *entry;

  directory = opendir(dir_name);
  if (directory != NULL)
  {
    while ((entry = readdir(directory)) != NULL)
    {
      printf("%s\n", entry->d_name);
    }
    closedir(directory);
  }
  else
  {
    printf("Directory doesnt exist. %s\n", dir_name);
    exit(1);
  }
}

/**
 * Main
 */

int main(int argc, char **argv)
{
  // Parse command line
  int x;

  x = 1;
  while (x < argc)
  {
    ls_dir(argv[x]);
    x++;
  }

  if (argc == 1)
  {
    ls_dir(".");
  }

  return 0;
}