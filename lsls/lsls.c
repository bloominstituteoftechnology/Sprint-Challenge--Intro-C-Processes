#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
  struct stat buf;
  struct dirent *de;
  char *dirname;

  if (argc > 2)
  {
    printf("Error: Too many command line arguments \n");
    exit(1);
  }
  else if (argc == 1)
  {
    dirname = ".";
  }
  else
  {
    dirname = argv[1];
  }

  DIR *d = opendir(dirname);

  if (d == NULL)
  {
    printf("Error: Directory not found.\n");
    exit(1);
  }

  char path[] = "./";

  while ((de = readdir(d)) != NULL)
  {
    char *pathcpy = strdup(path);
    strcat(pathcpy, de->d_name);
    stat(pathcpy, &buf);
    printf("%lld %s\n", buf.st_size, de->d_name);
  }
  closedir(d);
  return 0;
}