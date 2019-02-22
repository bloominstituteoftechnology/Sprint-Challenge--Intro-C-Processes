#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  printf("argc : %d\n", argc);
  int index = 0;
  for (index = 0; index < argc; index++) {
    printf("argv[%d] : %s\n",index, argv[index]);
  }

  // Open directory

  // Repeatly read and print entries

  // Close directory

  return 0;
}