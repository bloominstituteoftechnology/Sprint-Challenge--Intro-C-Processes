#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv) // main takes in a argv pointer. Is argc number or args given?
{
  struct dirent *pointDir; // struct that finds serial # and Directory name
  char *directoryName; // Store directory name in a pointer

  if(argc == 1) // need to check that arg[1] is set to something
  {
    directoryName = "."; // set dir

  } else if(argc == 2) {

    directoryName = opendir(argv[1]);
    return 1;

  } else {

    printf("No directory exists\n");
    return 1;
  }

  // Now I need to iterate and find all directories. Do... While? Or NULL check? With while loop?
  DIR *dir = opendir(directoryName);
  if(directoryName == NULL) // check if there is a dir to open.
  {
    printf("Trouble opening directory\n");
    // exit(1);

  } else {
    
    while((pointDir = readdir(dir)) != NULL) // reads from the directory given in opendir to read via dir Struct
    {
      printf ("%s\n", pointDir->d_name); // prints out a list of all directories
    }

  }

  // we need to close the directory after its done running.
  closedir(dir);


  return 0;
}