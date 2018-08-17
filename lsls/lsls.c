#include <stdio.h>  // printf function access
#include <stdlib.h> // exit() function access
#include <dirent.h> // holds the declarations for DIR, struct dirent, opendir(), readdir(), and closedir()

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *dir;          // initializing a pointer to variable dir of type DIR
  struct dirent *dp; // initializing a pointer to a struct dirent named dp

  // Parse command line

  // Open directory path named in opendir() and return a pointer to dir
  if ((dir = opendir(".")) == NULL) // if there is an error opendir() returns NULL. We will print a standard error message in these cases
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