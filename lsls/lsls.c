#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char *dir_name;
  DIR *dp;
  dirent *enter;
  stat fileStat;

  // Open directory

  // check if no input
  if (argc <= 1)
  {
    // print current directory
    dir_name = ".";
  }
  // if directory in input (argv[1]), make a ref to it
  else if (argc == 2)
  {
    dir_name = argv[1];
  }
  // catch any errors or incorrect directories
  else
  {
    printf("Cannot open dir '%s'!!", argv[1]);
  }

  // Repeatly read and print entries

  // Close directory

  return 0;
}