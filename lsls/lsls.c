#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Define dirname based on arg count
  const char *dirname;
  if (argc == 1)
  {
    dirname = ".";
  }
  else
  {
    dirname = argv[1];
  }

  // Open directory
  DIR *dir;
  struct dirent *entry;

  // Error handling
  if ((dir = opendir(dirname)) == NULL)
  {
    fprintf(stderr, "Cannot open %s", dirname);
    exit(1);
  }

  // Repeatly read and print entries
  while ((entry = readdir(dir)) != NULL)
  {
    struct stat buf;
    char *fullpath = ("%s/%s", dirname, entry->d_name);
    stat(fullpath, &buf);
    printf("%10lld %s\n", buf.st_size, entry->d_name);
  }
  // Close directory
  closedir(dir);
  return 0;
}