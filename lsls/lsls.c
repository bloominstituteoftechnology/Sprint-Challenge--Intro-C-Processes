#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // check the amount of arguments passed to argv.
  
  

  // initiate my variables.
  struct dirent *pDirent;
  char *path[1];
  if (argc < 2) {
    *path = ".";
  }
  else
  {
     *path = argv[1];
  }
  
  DIR *pDir;

  // Open directory
  pDir = opendir(*path);
  
  if (pDir == NULL) {
    fprintf(stderr, "failed to open directory: %s\n", *path);
    return 1;
  }
  
  // Repeatly read and print entries
 
  while ( (pDirent = readdir(pDir)) != NULL) {
      
      printf ("[%s]\n", pDirent->d_name);
  }
  
  
  // Close directory
  closedir(pDir);
  
  return 0;
}