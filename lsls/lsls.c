#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * Main
 */

int main(int argc, char **argv)
{

  char *pathname; // initialize char-ptr for pathname
  DIR *directory; // initialize type DIR for opening directory
  struct dirent *entry; //initialize dirent for reading directory

  // Parse command line
  if (argc == 1) { 
    pathname = "."; // if no pathname is passed in, then use current directory
  } else if (argc == 2) {
    pathname = argv[1]; // else use pathname passed in
  } else {
    fprintf(stderr, "Too many arguments! Please only pass one pathname.\n");
    exit(-1); // else exit because too many arguments were passed in
  }

  // Open directory
  directory = opendir(pathname); // assign directory to pathname stream
   if (directory == NULL) {
    fprintf(stderr, "%s is not a valid pathname.\n", pathname);
    exit(-2); // exit if pathname is not valid
  }

  // Repeatly read and print entries
   while ((entry = readdir(directory)) != NULL) {
     printf("%s\n", entry->d_name); // print name of directory from d_name field of dirent struct   
  }

  // Close directory
  closedir(directory); // don't forget to close it!
  return 0;
}