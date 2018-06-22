#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char *name;
  if (argc = 1)
  {
    name = ".";
  }
  else if (argc == 2)
  {
    name = argv[1];
  }
  else
  {
    fprintf(stderr, "Usage: ./lsls [name]\n");
  }

  // Open directory
  DIR *dir;
  struct dirent *sd;
  dir = opendir(name);

  if (dir == NULL)
  {
    printf("Unable to open the directory.", name);
    exit(1);
  }

  // Repeatly read and print entries
  while ((sd = readdir(dir)) != NULL)
  {
    //printf("%s\n", sd->d_name);
    //filesize
    char fullpath[10000];
    struct stat stat_buf;
    //fullpath
    snprintf(fullpath, sizeof(fullpath), "%s/%s", name, sd->d_name);
    if (stat(fullpath, &stat_buf) == -1)
    {
      fprintf(stderr, "Failed to stat file %s\n", fullpath);
      exit(3);
    }

    if (stat_buf.st_mode & S_IFREG)
    {
      // file name and size in bytes
      printf("%10lld %s\n", stat_buf.st_size, sd->d_name);
    }
    else if (stat_buf.st_mode & S_IFDIR)
    {
      // directory
      printf("%10s %s\n", "<DIR>", sd->d_name);
    }
    else
    {
      printf("%10s %s\n", "", sd->d_name);
    }
  }

  // Close directory
  closedir(dir);
  return 0;
}