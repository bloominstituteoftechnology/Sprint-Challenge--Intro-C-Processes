#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  
  // Open directory
  char* myargs[] = { "ls", ".", NULL };
  execvp("ls", myargs);

  // Repeatly read and print entries

  // Close directory

  return 0;
}