#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char *argv)
{
  //variables
  DIR *dir;
  char str[80]
  // Parse command line
  
  // Open directory
  dir  = opendir(argv);

  sprintf(str, '%p', dir);



  // Repeatly read and print entries

  // Close directory

  return 0;
}