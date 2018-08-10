#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  char *currdir = argc > 1 ? argv[1] : ".";
  DIR *dir = opendir(currdir);
  struct dirent *rdir;

  if (dir == NULL)
  {
    fprintf(stderr, "%s is not a valid directory", currdir);
    exit(1);
  }

  printf("$ %s %s\n", argv[0], currdir);
  while ((rdir = readdir(dir)) != NULL)
  {
    printf("%s\n", rdir->d_name);
  }

  closedir(dir);
  return 0;
}