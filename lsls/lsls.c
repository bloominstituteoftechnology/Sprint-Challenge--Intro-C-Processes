#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  struct dirent *de; // Pointer for directory entry

  // Parse command line
  // substitute a variable first
  // char *test_dir = argv[1] || ".";
  char *test_dir = ".";

  // Open directory
  DIR *dr = opendir(test_dir); // opendir returns a pointer of DIR type

  if (dr == NULL) 
  {
    printf("Could not open directory %s", test_dir);
    return 0;
  }

  // Repeatly read and print entries
  // printf("Running 1 of  %d\n", argc-1);
  while ((de = readdir(dr)) != NULL) 
  {
    printf("%s\n", de->d_name);
  }
  // Close directory

  return 0;
}