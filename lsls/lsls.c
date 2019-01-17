#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // initialize dir with a pointer
  DIR *dir = opendir(argv[1]);

  int *nbytes = malloc(500 * sizeof(int));
  for(int i =0; i < 500; i++) {
    *(nbytes + i) = argv;
  }
  
  // establishing struct
  struct dirent *pir;
  // less than 2 arguments = path not specified, so show current directory
  if (argc < 2) {
    dir = opendir(".");
  } else {
    // error handling
    if (dir == NULL) {
      printf("Directory %s could not be opened.\n", argv[1]);
      return 0;
    }
  }
  // as long as the dir does not = null, print it out
  while((pir = readdir(dir)) != NULL) {
    printf("%s bytes: %d\n", pir->d_name, nbytes);
  }
// Close directory
  closedir(dir);
  return 0;
}
 

