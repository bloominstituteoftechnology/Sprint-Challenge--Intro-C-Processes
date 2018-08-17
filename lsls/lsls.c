#include <stdio.h>  // printf function access
#include <stdlib.h> // exit() function access
#include <dirent.h> // holds the declarations for DIR, struct dirent, opendir(), readdir(), and closedir()

/**
 * Main
 */
int main(int argc, char **argv) //taking parameters of argument count, and a pointer to an array of argument values
{
  DIR *dir;          // initializing a pointer to variable dir of type DIR
  struct dirent *dp; // initializing a pointer to a struct dirent named dp

  // Parse command line
  if (argc == 2) // if argument count is greater than 1
  {
    dir = opendir(argv[1]); // open directory path passed in as the second argument after ./lsls
  }
  else if (argc == 1)
  {
    dir = opendir("."); // Open directory path named in opendir() and return a pointer to dir
  }

  if (dir == NULL) // if there is an error opendir() returns NULL. We will print a standard error message in these cases
  {
    fprintf(stderr, "Cannot open dir\n");
    exit(1);
  }
  // Repeatly read and print entries
  while ((dp = readdir(dir)) != NULL) // readdir() returns NULL when there are no more directory entries.
  {
    printf("%s\n", dp->d_name); // While there are entries print out the d_name field of the dp struct we declared
  }
  // Close directory
  closedir(dir); // closes the directory opened previously by opendir() when we are done
  return 0;
}