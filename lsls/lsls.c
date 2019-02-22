#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/wait.h>

//prints out a directory listing for the directory the user specifies on the command line. 
//The directory listing will include both file names and sizes. 

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  //If the user does not specify a directory, print out the contents of the current directory, which is called .
  int i;
  char *path;
  DIR *dir;

  if (argc > 1) 
  {
    path = argv[1];
  }
  else 
  {
    path = ".";
  }

  // Open directory

  if (path)
  {
    dir = opendir(path);
  }
  if (dir == NULL) 
  {
    fprintf(stderr, "error opening directory\n");
    exit(1);
  }

  // Repeatly read and print entries



  // Close directory
  closedir(dir);

  return 0;
}