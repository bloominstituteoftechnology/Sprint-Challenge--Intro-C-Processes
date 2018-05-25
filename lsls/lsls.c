#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

int printSize(char *path)
{
  struct stat buf;
  if (lstat(path, &buf) != -1)
  {
    return buf.st_size;
  }
  perror("stat");
  return -1;
}
int printIsDir(char *path)
{
  struct stat buf;
  if (lstat(path, &buf) != -1)
  {
    return S_ISDIR(buf.st_mode);
  }
  return -1;
}
/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *dir;
  struct dirent *dp;
  char *filename = ".";
  char path[100];

  // Parse command line
  printf("%d\n", argc);
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
    if (strcmp(dp->d_name, ".") != 0 || strcmp(dp->d_name, "..") != 0)
    {

      sprintf(path, "%s/%s", filename, dp->d_name);
      int size = printSize(path);
      if (printIsDir(path) > 0)
      {
        printf("%11s %s\n", "<DIR>", dp->d_name);
      }
      else if (size != -1)
      {
        printf("%11d %s\n", size, dp->d_name);
      }
      else
      {
        printf("%11s %s\n", " ", dp->d_name);
      }
      // printf("%s %s\n", "Pathname:", path);
      // printf("%s %s\n", "Filename: ", filename);
    }
  }

  // Close directory
  closedir(dir);

  return 0;
}