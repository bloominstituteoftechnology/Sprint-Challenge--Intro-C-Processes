#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  // By default the current directory is represented by "."
  char *directoryToEnumerate = ".";

  // Open directory
  DIR *directoryEnumerator = opendir(directoryToEnumerate);
  
  if (directoryEnumerator == NULL) {
    perror("Error opening directory");
    exit(1);
  }

  // Repeatly read and print entries
  struct dirent *directoryEntry;
  
  while ((directoryEntry = readdir(directoryEnumerator))) {
    // Get the name of the directory entry
    char *fileName = directoryEntry->d_name;  // Use -> b/c directoryEntry is a pointer
    
    printf("  %s\n", fileName);
  }

  // Close directory
  closedir(directoryEnumerator);

  return 0;
}