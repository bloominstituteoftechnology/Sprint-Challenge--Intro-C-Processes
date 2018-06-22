#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // check the amount of arguments passed to argv.
  
  if (argc < 2) {
    fprintf(stderr, "failed to add the directory.");
    return 1;
  }

  // initiate my variables.
  struct dirent *pDirent;
  DIR *pDir;
  char *path[] = { argv[1] };

  // Open directory
  pDir = opendir(*path);
  
  if (pDir == NULL) {
    fprintf(stderr, "failed to open directory: %s", *path);
    return 1;
  }
  
  // Repeatly read and print entries
  
  while ((pDirent = readdir(pDir)) != NULL) {
      printf ("[%s]\n", pDirent->d_name);
  }
  
  
  // Close directory
  closedir(pDir);
  
  return 0;
}