#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  DIR *dr;
  struct dirent *de;
  // Open directory
  if (argc == 1) {
    dr = opendir(".");
  }
  else if (argc == 2) {
    dr = opendir(argv[1]);
  }
  else 
  {
    fprintf(stderr, "Error opening the file\n");
  }
  // Repeatly read and print entries
  if (dr == NULL) 
  {
    // printing error results
    fprintf(stderr, "Error reading entries\n");
  } 
  else 
  {
    // Close directory
    while ((de = readdir(dr)) != NULL)
      printf("%s\n", de->d_name);
  }
  closedir(dr);
  return 0;
}