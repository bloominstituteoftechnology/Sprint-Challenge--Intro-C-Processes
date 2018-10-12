#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  if (argc < 2) {
    printf('Usage: ./lsls <directory name>');
    return 0;
  }

  // Open directory
  DIR *directory;
  if(directory == NULL) {
    printf("Cannot open directory '%s'\n", argv[1]);
  } else {
    directory = opendir('.');
  }
  // Repeatly read and print entries

  // Close directory

  return 0;
}