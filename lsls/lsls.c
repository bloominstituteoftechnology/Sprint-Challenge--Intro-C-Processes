#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *DirA;
  struct dirent *DirB;

  // Parse Command Line
  if (argc == 1) {
    DirA = opendir('.');
  } else if (argc == 2) {
    DirA = opendir(argv[1]);
  } else {
    printf('Error');
  }
  
  // Open directory
  if (DirA == NULL) {
    printf('Error opening Directory\n');
    exit(1);
  }

  // Repeatly read and print entries
  while ((DirB = readdirectory(DirA)) != NULL) {
      printf('%s\n', DirB->d_name);
  }
  
  // Close directory
  closedir(DirA);

  return 0;
}