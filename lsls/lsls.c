#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  struct dirent *pDirent;
  DIR *pDIR;
  
  // Parse command line
  if (argc < 2) {
    pDIR = opendir(".");
  }

  // Open directory
  else {
    pDIR = opendir(argv[1]);
  
    if (pDIR == NULL) {
      printf("Cannot open directory '%s'\n", argv[1]);
      exit(1);
    }
  }

  // Repeatly read and print entries
  while ((pDirent = readdir(pDIR)) != 0) {
    printf("%s\n", pDirent->d_name);
  }

  // Close directory
  closedir(pDIR);

  exit(0);
}
