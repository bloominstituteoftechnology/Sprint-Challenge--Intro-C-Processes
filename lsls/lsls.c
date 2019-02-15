#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *odir;
  struct dirent *rdir;
  struct stat buf;
  char *path;
  // Parse command line
  if (argc < 2)
  {
    path = ".";
  }
  else if (argc > 2)
  {
    printf("usage: ./lsls pathname");
  }
  else
  {
    path = strtok(argv[1], " \t\n\r");
  }

  printf("%s\n", path);

  // Open directory
  odir = opendir(path);
  if (odir == NULL)
  {
    fprintf(stderr, "Cannot find directory\n");
    exit(2);
  }
  // printf("Pointer: %p\n", odir);
  // Repeatly read and print entries
  while ((rdir = readdir(odir)) != NULL)
  {
    // printf("%s\n", rdir->d_name);
    stat(rdir->d_name, &buf);

    printf("%10ld %s\n", buf.st_size, rdir->d_name);
  }

  // Close directory
  closedir(odir);

  return 0;
}