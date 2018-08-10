#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  char *currdir = argc > 1 ? argv[1] : ".";
  struct dirent *rdir;
  struct stat fstatus;
  DIR *dir = opendir(currdir);

  if (dir == NULL)
  {
    fprintf(stderr, "%s is not a valid directory", currdir);
    exit(1);
  }

  printf("$ %s %s\n", argv[0], currdir);

  while ((rdir = readdir(dir)) != NULL)
  {
    char *path = strdup(currdir);
    strcat(strcat(path, "/"), rdir->d_name);

    if (stat(path, &fstatus) == 0)
    {
      printf("%10lld bytes  %s\n", fstatus.st_size, rdir->d_name);
    }

    free(path);
  }

  closedir(dir);
  return 0;
}