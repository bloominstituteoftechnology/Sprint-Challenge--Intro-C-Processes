#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>


/**
 * Main
 */

int main(int argc, char **argv)
{

   char *dir_name;
  // we check if there are no additional arguments added, just print current directory
  if (argc == 1)
  {
    dir_name = ".";
  }
  // We have arguments, print that directory
  else if (argc  > 1)
  {
    dir_name = argv[1];
  }
  // We have an error
  else
  {
    fprintf(stderr, "Something bahhhd! Usage: './lsls (dir_name)\n");
    exit(1);
  }
  // Open directory
  struct dirent *de;  //Pointer for directory entry
  DIR *dir = opendir(dir_name);
  // read and print entries
  if (dir)
  {
    while ((de = readdir(dir)) != NULL)
    {

       printf("%s\n", de->d_name);

    }
  // Close directory
    closedir(dir);
  }

  return 0;
}