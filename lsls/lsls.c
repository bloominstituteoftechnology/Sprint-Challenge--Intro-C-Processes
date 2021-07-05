#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
/**
 * Main
 */

size_t getFilesize(const char* filename);


int main(int argc, char **argv)
{

  //A type representing a directory stream
  DIR *dir;

  //Format of directory entreis
  //d_name[] specifies the name of entry
  struct dirent *de;

  struct stat buf;
  int exists;
  size_t total_size;
  

  // Parse command line
  printf("There are %d command line argument(s):\n", argc);

  for (int i = 0; i < argc; i++) {
      printf("   %s\n", argv[i]);
  }


  //If user doesn't specify an arguement directory equals current directory
  if (argc == 1) {
    dir = opendir(".");
  } else if (argc == 2) {
    dir = opendir(argv[1]);
  } else {
    fprintf(stderr, "Could not read commandline\n");
  }

  // Open directory
  
  //Check if directory never gets set
  if (dir == NULL) {
    fprintf(stderr, "Error, no directory\n");
    exit(1);
  }

  

  // Repeatly read and print entries
  while ((de = readdir(dir)) != NULL) {
    total_size = getFilesize(de->d_name);
    printf("%zd  %s\n", total_size, de->d_name);
  }


  // Close directory
  closedir(dir);
  return 0;
}

//Gets and returns the file size
size_t getFilesize(const char* filename) {
    struct stat st;
    if(stat(filename, &st) != 0) {
        return 0;
    }
    return st.st_size;   
}