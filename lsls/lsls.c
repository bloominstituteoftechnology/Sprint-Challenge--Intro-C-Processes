#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line

  char *path;
  if(argv[1] != NULL){
    path = argv[1];
  }
  else{
    path = ".";
  }

  // Open directory

  DIR *directory = opendir(path);

  // Repeatly read and print entries

  if(directory == NULL){
    fprintf(stderr,"error opening directory\n");
    exit(1);
  }
  struct dirent *entry;
  while( (entry = readdir(directory)) != NULL){
    printf("%s\n",entry->d_name);
  }

  // Close directory

  closedir(directory);

  return 0;
}
