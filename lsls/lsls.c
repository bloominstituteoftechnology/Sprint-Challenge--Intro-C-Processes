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
  char* path;
  struct stat statbuf;
  char* dir = "<DIR>";
  if (argc > 1)
    path = argv[1];
  else
    path = ".";
  printf("%s\n", path);
  // Open directory
  DIR *target = opendir(path);
  if (target == NULL){
    printf("%s\n", "Cannot open directory");
    exit(1);
  }
  // Repeatly read and print entries
  struct dirent *dp;
  while(dp = readdir(target)) {
    stat(dp->d_name, &statbuf);
    if (statbuf.st_size != 0)
      printf("%10lld %s\n", statbuf.st_size, dp->d_name);
    else
      printf("%10lls %s\n", dir, dp->d_name);
  }
  // Close directory
  closedir(target);
  return 0;
}