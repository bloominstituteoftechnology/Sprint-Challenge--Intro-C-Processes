#include <stdio.h>
#include <dirent.h> // let's us open a directory

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  
  // Open directory

  // Repeatly read and print entries

  // Close directory

  // print out dictory listing user specifies on command line.
  // IF no directory specified then print contents of current directory

  DIR *directory = opendir(".");
  char *result = directory == NULL ? "Did not open" : "Succeded!"; // ternary operator
  printf("Testing opening a directory:  %s\n", result);
  closedir(directory);

  return 0;
}