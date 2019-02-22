#include <stdio.h>
#include <dirent.h>

struct dirent *pDirent;
DIR *pDir;
char dir;

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  if (argc < 2) {
    pDir = opendir(".");
  } else {
    pDir = opendir(argv[1]);
  }

  // Open directory

  while(pDir != NULL) {
    pDirent = readdir(pDir);
    printf("%s\n", pDirent->d_name);
  }

  // Repeatly read and print entries

  // Close directory
  closedir(pDir);

  return 0;
}