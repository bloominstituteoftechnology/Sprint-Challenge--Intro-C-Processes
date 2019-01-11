#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *dir;
  struct dirent *dp;
  struct stat buf;
  // Parse command line
  if (argc < 2) {
    printf("Open: ./lsls <directory>\n");
    return 1;
  }

  // Open directory
  dir = opendir(argv[1]);
  if (dir == NULL) {
    printf("Cannot open '%s'\n", argv[1]);
    return 1;
  }
  // if ((dir = opendir (argv[1])) == NULL) {
  //   perror("Cannot open '%s'\n", argv[1]);
  //   exit(1);
  // }

  // Repeatly read and print entries
  if ((dp = readdir(dir)) != NULL) {
    stat(dp->d_name, &buf);
    if (strcmp(dp->d_name, argv[1]) != 0) {
      printf("%s\n", dp->d_name);
      printf("file size is %lld\n", buf.st_size);
      
      return -1;
    }
  }

  // Close directory
  closedir(dir);

  return 0;
}