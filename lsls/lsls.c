#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/types.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  
  DIR *dir;
  struct dirent *sd;

  // Parse command line
  

  printf("There are %d command line argument(s):\n", argc);

  for (int i = 0; i < argc; i++) {
    printf("   %s\n", argv[i]);
    }

  if (argc == 1) {
    dir = opendir(".");
  }
  else if (argc == 2) {
    dir = opendir(argv[1]);
  }
  else {
    fprintf(stderr, "Could not read commandline\n");
  }

  // Open directory

  if (dir == NULL) {
    fprintf(stderr, "Error, cannot open directory!\n");
    exit(1);
  }

  // Repeatly read and print entries
  while((sd = readdir(dir)) != NULL) {
    printf(">> %s\n", sd->d_name);
  }

  // Close directory
  closedir(dir);

  return 0;
}