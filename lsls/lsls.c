#include <stdio.h>    // printf function access
#include <stdlib.h>   // exit() function access
#include <dirent.h>   // holds the declarations for DIR, struct dirent, opendir(), readdir(), and closedir()
#include <sys/stat.h> // contains the struct stat and stat() needed to print file size in bytes.

/**
 * Main
 */
int main(int argc, char **argv) //taking parameters of argument count, and a pointer to an array of argument values
{
  DIR *dir;           // initializing a pointer to variable dir of type DIR
  struct dirent *dp;  // initializing a pointer to a struct dirent named dp
  struct stat buffer; // structure variable buffer is defined for the stat structure

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
    int status = stat(dp->d_name, &buffer); // The stat() function obtains information about the named file and writes it to the area pointed to by the buffer argument (struct stat buffer).
    // declaring status an integer value to capture if the stat function returns a 0 or a -1
    if (status == -1) // upon successful completion, 0 is returned. Otherwise -1 is returned to indicate an error.
    {
      fprintf(stderr, "Failed stat function at %s\n", dp->d_name);
    }
    printf("%10ld  %s\n", buffer.st_size, dp->d_name); // While there are entries print out the file size in bytes from st_size field of the buffer struct and d_name field of the dp struct we declared
  }
  // Close directory
  closedir(dir); // closes the directory opened previously by opendir() when we are done
  return 0;
}