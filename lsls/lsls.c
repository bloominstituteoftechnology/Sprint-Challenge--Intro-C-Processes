#include <stdio.h>
#include <unistd.h>
#include <dirent.h>	#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>


/**
 * Main
 */





int main(int argc, char **argv)
{
  // Parse command line
  int i;
  printf("There are %d command line arguments:\n", argc);
  for (i = 0; i < argc; i++) {
    printf("  %s\n", argv[i]);
  }
  char *dirname;
  if (argc == 1) {
    dirname = ".";
  }
  else  {
    dirname = argv[1];
  }
  printf("Directory is : %s\n", dirname);
  // Open directory
  DIR *d;
  d = opendir(dirname);
  if (d == NULL) {
    printf("directory not found");
    exit(0);
  }
  // Repeatly read and print entries
  else{
    struct dirent *dir;
    while( (dir  = readdir(d))  != NULL){
      if ( dir != NULL) {
        struct stat statbuf;
        stat(dir->d_name, &statbuf);
        printf("%10ld %s\n", statbuf.st_size, dir->d_name);
      }
      else{
        exit(0);
      }
    }
  }
  // Close directory
  closedir(d);
  return 0;
}

