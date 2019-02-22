#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char *path = argv[1] != NULL ? argv[1] : ".";
  // Open directory
  DIR *dir = opendir(path);
  // Repeatly read and print entries
  struct dirent *ent;
  while((ent == readdir(dir)) != NULL){

  }
  // Close directory

  return 0;
}