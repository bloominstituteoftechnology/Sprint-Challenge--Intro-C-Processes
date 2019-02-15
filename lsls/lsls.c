#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char commandline[1024];

  while (1)
  {
    printf("Please enter a directory\n");
    fgets(commandline, sizeof(commandline), stdin);
    printf("COMMAND: %s\n", commandline); // <-- Debugging
  }

  // Open directory

  // Repeatly read and print entries

  // Close directory

  return 0;
}