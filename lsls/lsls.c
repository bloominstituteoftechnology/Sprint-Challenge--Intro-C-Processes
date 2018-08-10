#include <stdio.h>
#include <dirent.h> // let's us open a directory

/**
 * Main
 */
int main(int argc, char **argv)
{
  // ***print out dictory listing user specifies on command line.
  // ***IF no directory specified then print contents of current directory

  // Parse command line
    //printf(suser pecify directory)
  // Open directory
    //opendir()
  // Repeatly read and print entries
    //readdir() return NULL when no more entries
  // Close directory
    //closedir()

  DIR *directory = opendir(".");
  char *result = directory == NULL ? "Did not open" : "Succeded!"; // ternary operator
  printf("Testing opening a directory:  %s\n", result);
  closedir(directory);

  return 0;
}