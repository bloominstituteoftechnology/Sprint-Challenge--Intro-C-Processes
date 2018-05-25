#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

int printSize(char *path)
{
  struct stat buf;
  stat(path, &buf);
  return buf.st_size;
}
int printIsDir(char *path)
{
  struct stat buf;
  stat(path, &buf);
  return S_ISDIR(buf.st_mode);
}
/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *dir;
  struct dirent *dp;
  char *filename = ".";

  // Parse command line
  if (argc == 2)
  {
    filename = argv[1];
  }
  else if (argc > 2)
  {
    fprintf(stderr, "You can only list the contents of one directory at a time.\n");
  }

  // Open directory
  if ((dir = opendir(filename)) == NULL)
  {
    fprintf(stderr, "Cannot Open .");
    exit(1);
  }

  // Repeatly read and print entries

  while ((dp = readdir(dir)) != NULL)
  {
    char *path = ("/%s", dp->d_name);
    int size = printSize(path);
    if (printIsDir(path))
    {
      printf("%11s %s\n", "<DIR>", dp->d_name);
    }
    else
    {
      printf("%11d %s\n", size, dp->d_name);
    }
  }

  // Close directory
  closedir(dir);

  return 0;
}