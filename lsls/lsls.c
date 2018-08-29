#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  char *dirname;

  if (argc == 1) {
    dirname = ".";
  } else if (argc == 2)  {
    dirname = argv[1];
  } else {
    fprintf(stderr, "provide a valid directory name.\n");
    exit(1);
  }
  
  DIR *directory;
  struct dirent *dir;
  directory = opendir(".");

   if (directory == NULL) {
    fprintf(stderr, "The directory %s cannot be opened.", dirname);
    exit(1);
  }

  while ((dir = readdir(directory)) != NULL) {
    printf("Open directory: %s\n", dir->d_name);
  }

  closedir(directory);
  return 0;	 
} 