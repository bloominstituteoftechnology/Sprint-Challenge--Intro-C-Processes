#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  if (argc < 2)
  {
    fprintf(stderr, "usage: lsls <dirname>\n");
    exit(1);
  }

  char *dirname = argv[1];

  // Open directory

  // Repeatly read and print entries

  // Close directory

  return 0;
}