#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line

  // Open directory
  DIR *dir;
  dir = opendir();

  if (!dir)
  {
    perror("The directory could not be opened.");
  }

  // Repeatly read and print entries
  readdir();

  // Close directory
  closedir();

  return 0;
}