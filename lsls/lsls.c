#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char *argv)
{
  //variables
  DIR *dir;
  char *str[80];
  struct dirent *ent;
  // Parse command line
  
  // Open directory
  dir = opendir(argv);

  ent = readdir(dir);

  printf("%s\n",ent->d_name);



  // Repeatly read and print entries

  // Close directory

  return 0;
}