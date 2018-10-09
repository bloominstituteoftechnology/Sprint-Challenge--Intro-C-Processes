#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <limits.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  DIR *dir;
  struct dirent *dp;
  char *dir_name;

  if (argc >= 2) {
    dir_name = argv[1];
  } else {
    dir_name = ".";
  }

  // Open directory
  if ((dir = opendir(dir_name)) == NULL) {
    perror("Error opening directory.");
    exit(1);
  }

  struct stat buf;
  char fullpath[PATH_MAX + 1];

  // Repeatly read and print entries
  while ((dp = readdir(dir)) != NULL) {
    realpath(dp->d_name, fullpath);
    stat(fullpath, &buf);
    printf("%10lld", buf.st_size);
    printf("%20s\n", dp->d_name);
  }

  // Close directory
  closedir(dir);

  return 0;
}