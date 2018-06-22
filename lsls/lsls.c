#include <stdio.h>
#include <dirent.h>
// #include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  DIR *dir;
  // struct dirent *dp;
  char *path;

  if (argc == 1)
  {
    path = ".";
  }
  else if (argc == 2)
  {
    path = argv[1];
  }
  else
  {
    printf(
        "Too many command line arguments!\n"
        "There are %d command line argument(s) but should only be 1 or 2.\n",
        argc);
  }
  // Open directory
  dir = opendir(path);
  if (dir == NULL)
  {
    printf("Can't open current dirrectory.\n");
    return 0;
  }
  // Repeatly read and print entries
  while (dir > 0)
  {
    struct dirent *ent = readdir(dir);
    printf("%s\n", ent->d_name);
  }
  if (dir == 0)
  {
    printf("Empty directory.\n");
    return 0;
  }

  // Close directory
  closedir(dir);

  return 0;
}