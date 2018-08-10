#include <stdio.h>
#include <dirent.h>
#include <unistd.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line

  // Open directory

  // Repeatly read and print entries

  // Close directory

  if (argc == 1) {
      execv("/bin/ls", argv);
  }

  return 0;
}