#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  struct dirent *pDirent;
  struct stat filestats;
  DIR *pDIR;
  char buf[512];
  
  // Parse command line
  if (argc < 2) {
    pDIR = opendir(".");
    argv[1] = ".";
  }

  // Open directory
  else {
    pDIR = opendir(argv[1]);
  
    if (pDIR == NULL) {
      printf("''%s' is not a directory\n", argv[1]);
      exit(1);
    }
  }

  // Repeatly read and print entries
  while ((pDirent = readdir(pDIR)) != 0) {
      sprintf(buf, "%s/%s", argv[1], pDirent->d_name);
      stat(buf, &filestats);
    
    if (filestats.st_size != 4096) {
      printf("%ld", filestats.st_size);
    } else {
      printf("<DIR>");
    }
      printf(" %s\n", pDirent->d_name);
  }

  // Close directory
  closedir(pDIR);

  exit(0);
}
