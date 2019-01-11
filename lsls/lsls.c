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

  // Repeatly read and print entries

  // Close directory

  return 0;
}