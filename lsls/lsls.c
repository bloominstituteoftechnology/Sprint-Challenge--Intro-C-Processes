#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  char commands[1024];

  while(1) {
    printf("lssh$");

    fgets(commands, sizeof(commands), stdin);

    if(argc == 0) {
      return 0;
    }

  }
  // Parse command line

  // Open directory

  // Repeatly read and print entries

  // Close directory

  return 0;
}