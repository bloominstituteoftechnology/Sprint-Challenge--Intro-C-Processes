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
  if (argc < 2) {
    argv[1] = ".";
  }
  // Open directory
  DIR *d;
  d = opendir(argv[1]);
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
    if (buf.st_mode & S_IFDIR) {
      printf("<DIR> %s\n", entry->d_name);
    } else {
      printf("%ld %s\n", buf.st_size, entry->d_name);
    }
  }
  // Close directory
  closedir(d);
  return 0;
}