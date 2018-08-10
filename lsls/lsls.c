#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  //variables
  DIR *dir;
  // Parse command line
  
  // Open directory
  dir  = opendir(argv);

  printf((SA_FormatString)dir);



  // Repeatly read and print entries

  // Close directory

  return 0;
}