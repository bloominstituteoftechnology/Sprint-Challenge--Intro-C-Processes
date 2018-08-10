#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>


void ls_directory(const char *directory_name)
{
  // DIR type is defined in <dirent.h> and represents a directory stream
  // - an ordered sequence of all the directory entries in a directory
  DIR *directory;
  struct dirent *entry;

  // Open directory
  // opendir() returns a pointer to an object of type DIR if successful
  // if unsuccessful, opendir() returns a null pointer
  directory = opendir(directory_name);
  if (directory != NULL)
  {
    printf("\n***Start of ls call to %s***\n", directory_name);
      // Repeatly read and print entries
      // readdir() returns a pointer to a structure representing
      // the directory entry at the current position in the directory stream
      // - it returns a null pointer when it reaches the end 
      // of the directory stream
    while ((entry = readdir(directory)) != NULL)
    {
      printf("%s\n", entry->d_name);
    }
    printf("***End of ls call to %s***\n\n", directory_name);
  // Close directory
  // closedir closes the directory stream and returns 0 if successful
  // if unsuccessful, -1 is returned
  // The two ways in which closedir can fail are:
  // if the argument it is passed is not an open directory stream
  // or if the function was interrupted by a signal
    closedir(directory);
  }
  else
  {
    printf("Cannot open directory %s\n", directory_name);
    exit(1);
  }
}

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  int i;

  i = 1;
  // the first argument in argv is always going to be the file name
  // - take every argument after as an argument to ls
  while (i < argc)
  {
    ls_directory(argv[i]);
    i++;
  }

  if (argc == 1)
  {
    ls_directory(".");
  }

  return 0;
}