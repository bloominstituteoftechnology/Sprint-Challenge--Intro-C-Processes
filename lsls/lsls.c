#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  char *directoryPath;
  // Parse command line
/*
   If there there is no directory given than,
   this code reverts to a default of  ".".
*/
if(argc == 1)
{
  directoryPath=".";
}
/*
  else if there is a directory given take argive at the index of 1 and set the directory path to that.
*/
else if(argc == 2)
{
directoryPath = argv[1];
}
  // Open directory
  // set variable pointer for directory entries
  struct dirent *entry;
  /*
    Open the directory passing in the path that we parsed above, set that to a directory stream pointer, i named mine openDirectory
  */
DIR *openedDirecectory =opendir(directoryPath);
/*
  if the directory opened rturned Null, print an error
  and exit.
*/
  if (openedDirecectory ==NULL)
  {
    fprintf(stderr,"cannot open directory");
    exit(1);
  }
    // Repeatly read and print entries
    /*
      while there are still directorys to read and we are not getting null, then print out the directory name of the entry
    */
  while((entry = readdir(openedDirecectory)) !=NULL)
  {
    printf("Directory: %s\n", entry->d_name);
  }

  // Close directory
closedir(openedDirecectory);
  return 0;
}