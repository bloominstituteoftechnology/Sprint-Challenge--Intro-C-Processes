#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
    struct dirent *de;

  // Open directory
    DIR *dr = opendir(".");
    if (dr == NULL) {
      printf("Could not open current directory");
      return 0;
    }

  // Repeatly read and print entries
    while ((de = readdir(dr)) != NULL) {
      printf("%s\n", de -> d_name);
    }
    
  // Close directory
  closedir(dr);
  return 0;
}