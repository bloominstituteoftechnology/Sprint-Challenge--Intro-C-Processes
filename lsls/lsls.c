#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
/**
 * Main
 */
int main(int argc, char **argv)
{
  char *dirid;
  // Parse command line
  if (argc == 1)
  {
    dirid = '.';
  }
  else if (argc == 2)
  {
    
  }

  // Open directory
  DIR *dirpoint = opendir(dirid);
  if (d == NULL) // checking if directory exists based on DIR return
  {
    printf("This directiory cannot be found or opened: %s\n", dirpoint);
    exit(); // exit if directory name not found 
  }

  // Repeatly read and print entries

  // Close directory

  return 0;
}