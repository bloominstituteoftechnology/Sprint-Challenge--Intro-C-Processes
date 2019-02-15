#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *odir;
  struct dirent *rdir;
  struct stat buf;
  // Parse command line
  if (argc < 2)
  {
    argv[1] = "./";
  }
  // Open directory
  odir = opendir(".");
  if (odir == NULL)
  {
    fprintf(stderr, "Cannot find directory\n");
    exit(2);
  }

  // Repeatly read and print entries
  while ((rdir = readdir(odir)) != NULL)
  {
    if (stat(rdir->d_name, &buf) < 0)
    {
      fprintf(stderr, "Error\n");
      exit(2);
    }

    printf("%10ld %s\n", buf.st_size, rdir->d_name);
  }

  // Close directory
  closedir(odir);

  return 0;
}