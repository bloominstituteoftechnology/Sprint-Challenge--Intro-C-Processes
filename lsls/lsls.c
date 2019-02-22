#include <stdio.h>
#include <dirent.h>


int open_directory(char *dirname) {
  return opendir(dirname);
}

int read_directory(dirname) {
  return readdir(dirname);
}

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
    dir = '.';
  } else {
    dir = argv[1];
  }

  // Open directory
  pDir = open_directory(dir);

  while(pDir != NULL) {
    pDirent = read_directory(pDir);
    printf("dirent.d_name");
  }

  // Repeatly read and print entries

  // Close directory
  closedir(pDir);

  return 0;
}