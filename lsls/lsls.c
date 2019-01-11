#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  printf("\nCommand-line arguments:\n");
  for (int count = 0; count < argc; count++) {
    printf( " argv[%d]  %s\n", count, argv[count] );
  }
  // Open directory
  DIR *d;
  struct dirent *dir;
  d = opendir("../examples");
  // Repeatly read and print entries
  if (d) {
    while ((dir = readdir(d)) != NULL) {
      printf("%s\n", dir->d_name);
    }
  }
  // Close directory
  closedir(d);
  return 0;
}