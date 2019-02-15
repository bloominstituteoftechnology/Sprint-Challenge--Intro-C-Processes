#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  char *dirName;
  DIR *d;
  struct dirent *ent;
  struct stat buf;
  // Parse command line
  if(argc < 2) {
    dirName = ".";
  } else if (argc == 2) {
    dirName = argv[1];
  } else {
    printf("Could not open directory '%s'", argv[1]);
    return 1;
  }
  // Open directory
  
  // Repeatly read and print entries

  // Close directory

  return 0;
}