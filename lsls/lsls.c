#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  struct dirent *pDirent;
  DIR *pDir;
  
  // Parse command line
  if (argc < 2)
  {
    printf("Insufficient data provided --> Usage: name.exe <directory name>\n");
    return 1;
  }
  
  // Open directory
  pDir = opendir(argv[1]);
  if (pDir == NULL) {
    printf("Can't open dir %s \n", argv[1]);
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