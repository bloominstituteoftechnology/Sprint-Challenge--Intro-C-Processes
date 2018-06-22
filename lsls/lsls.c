#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  struct dirent *pDirent;
  DIR *pDir;
  char *path[1];

  // Parse command line
  if (argc < 2) {
    *path = ".";
  } else {
    *path = argv[1];
  }

  // Open directory
  pDir = opendir(*path);

  if (pDir == NULL) {
    printf("Error: failed to open directory %s\n", *path);
    return 1;
  }

  // Repeatly read and print entries
  while ((pDirent = readdir(pDir)) != NULL) {
    printf("[%s]\n", pDirent->d_name);
  }

  // Close directory
  closedir(pDir);

  return 0;
}