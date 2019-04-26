#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

#include <sys/stat.h>
#include <stdlib.h>
#include <dirent.h>


/**
 * Main

1. Call `opendir()`.
2. Then repeatedly call `readdir()`--printing the filenames as you go--until it
   lets you know there are no more directory entries by returning `NULL`.
3. Then call `closedir()`.
 */

int main(int argc, char **argv)
{
   // Parse command line
  struct stat buf;
  int exists;
  DIR *d;
  struct dirent *de;

  // Open directory
  d = opendir(".");
  if (d == NULL) {
    fprintf(stderr, "Couldn't open \".\"\n");
    exit(1);
  }

  // Repeatly read and print entries
  for (de = readdir(d); de != NULL; de = readdir(d)) {
    exists = stat(de->d_name, &buf);
    if (exists < 0) {
      fprintf(stderr, "%s not found\n", de->d_name);
    } else {
      printf("%s %lld\n", de->d_name, buf.st_size);
    }
  }
  // Close directory
  closedir(d);

  return 0;
}