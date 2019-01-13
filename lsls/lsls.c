#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>	


/**
 * Main
 */





int main(int argc, char **argv)
{
  // Parse command line
  char *dirname;
  if (argc == 1) {
    dirname = ".";
  }
  else if (argc == 2) {
    dirname = argv[1];
  }
  else {
    printf(stderr, "usage: lsls [dir]\n");
    exit(1);
  }
  // Open directory
  DIR *d;
  d = opendir(dirname);
  if (d == NULL) {
    printf(stderr, "lsls: cannot open %s\n", dirname);
    exit(2);
  }
  // Repeatly read and print entries
  struct stat file_stats;
  struct dirent *dir;
  if (d) {
    while ((dir = readdir(d)) != NULL) {
      printf("%s\n", dir->d_name);
      if (!stat(dir->d_name, &file_stats)) {
        printf("%u bytes\n", (unsigned int)file_stats.st_size);
      }
      else {
        printf("(stat() failed for this file)\n");
      }
    }
  }
  // Close directory
  closedir(d);
  return 0;
}