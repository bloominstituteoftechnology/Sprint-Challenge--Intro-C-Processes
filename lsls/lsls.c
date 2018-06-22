#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line

  // Open directory
  DIR *opendir(char *path);
  struct dirent *dp;

  if ((path = opendir ('.')) == NULL) {
      perror ('Cannot open directory');
      exit(1);
  }
  while ((dp = readdir (dir)) != NULL) {

  }
  // Repeatly read and print entries

  // Close directory
  closedir();

  return 0;
}