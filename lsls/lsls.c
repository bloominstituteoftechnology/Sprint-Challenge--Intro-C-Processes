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
  DIR *dir;
  struct dirent *dp;

  if ((dir = opendir ('.')) == NULL) {
      perror ('Cannot open .');
      exit(1);
  }
  while ((dp = readdir (dir)) != NULL) {

  }
  // Repeatly read and print entries

  // Close directory
  closedir();

  return 0;
}