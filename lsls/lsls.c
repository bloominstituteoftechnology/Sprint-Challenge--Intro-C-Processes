#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char *directory = NULL;

  if(argc == 1){
    // print current directory if no argument passed
    directory = ".";
  } else if(argc == 2) {
    // desired directory is argv[1]
    directory = argv[1];
  } else {
    fprintf(stderr, "Program only accepts one argument.\n");
  }

  // printf("%s\n", directory);

  DIR *dp; // initialize the directory pointer
  struct dirent *dir; // create a dirent struct from the directory
  dp = opendir(directory); // open the directory

  if(dp){ // if a valid dir is found...
    while((dir = readdir(dp)) != NULL){
      printf("%s\n", dir->d_name); // print its contents name on each new line
    }

    closedir(dp); // close the directory
  } else {
    fprintf(stderr, "Could not open the directory.\n");
  }
  
  return 0;
}