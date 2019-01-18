#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // initialize dir with a pointer
  DIR *dir = opendir(argv[1]);

  // establishing structs
  struct dirent *pir;
  struct stat sb;

  // less than 2 arguments = path not specified, so show current directory
  if (argc < 2) {
    dir = opendir(".");
  } else {
    // error handling
    if (dir == NULL) {
      printf("Directory %s could not be opened.\n", argv[1]);
      return 0;
    }
  }
  // as long as the dir does not = null, print it out
  while((pir = readdir(dir)) != NULL) {
    printf("Directory: %s   File size: %lld bytes\n", pir->d_name, (long long) sb.st_size);
  }
// Close directory
  closedir(dir);
  return 0;
}