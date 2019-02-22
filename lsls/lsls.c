#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line

  // Open directory
  DIR *d;
  // if (argc < 2) {
  //   d = opendir(".");
  // } else {
    d = opendir(argv[1]);
  // }
  
  if (d == NULL) {
    printf("opendir() failed");
    exit(1);
  }
  // Repeatly read and print entries
  struct dirent *entry;
  struct stat buf;
  char path[512];
  while (entry != NULL) {
    entry = readdir(d);
    sprintf(path, "%s/%s", argv[1], entry->d_name);
    stat(path, &buf);
    printf("%ld %s\n", buf.st_size, entry->d_name);
  }
  // Close directory
  closedir(d);
  return 0;
}