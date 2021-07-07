#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

//http://pubs.opengroup.org/onlinepubs/7990989775/xsh/readdir.html
/**
 * Main
 */
int main(int argc, char **argv)
{ int len;
  struct dirent *pDirent;
  DIR *pDir;

  // Parse command line

  if (argc < 2)
  {
    printf("Usage: ./lsls \n");
    return 1;
  }
  
  // Open directory

  pDir = opendir(argv[1]);


  if (pDir == NULL)
  {
    printf("Cannot open directory '%s'\n", argv[1]);
    exit(1);
  }
  // Repeatly read and print entries
  while ((pDirent = readdir(pDir)) != NULL)
  {
    printf("%s\n", pDirent->d_name);
  }

  // Close directory
  closedir(pDir);
  return 0;
}