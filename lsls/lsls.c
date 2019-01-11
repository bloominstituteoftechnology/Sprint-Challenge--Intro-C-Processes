#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>


size_t GetFileSize(const char *filepath){
    struct stat st;

    if(stat(filepath, &st) != 0){
      return -1;
    }

    if(S_ISDIR(st.st_mode)){
      return 0;
    } else {
      return st.st_size;
    }
  }

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
    exit(1);
  }

  DIR *dp; // initialize the directory pointer
  struct dirent *dir; // create a dirent struct from the directory
  dp = opendir(directory); // open the directory

  if(dp != NULL){ // if a valid dir is found...
    while((dir = readdir(dp)) != NULL){

      // create a full path to pass to GetFileSize
      char file_path[500] = "";
      strcat(file_path, directory);
      strcat(file_path, "/");
      strcat(file_path, dir->d_name);

      size_t size = GetFileSize(file_path); // get the file size

      if(size == 0){
        char *size_str = "<DIR>";
        printf("%10s  %-20s\n", size_str, dir->d_name);
      } else {
        printf("%10zu  %-20s\n", size, dir->d_name); // print its contents name on each new line
      }


    }

    closedir(dp); // close the directory
  } else {
    fprintf(stderr, "Could not open the directory.\n");
  }
  
  return 0;
}