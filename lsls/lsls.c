#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  char *dir_name;
  // Parse command line
  if (argc == 1)
  {
    dir_name = ".";
  }
  else if (argc == 2)
  {
    dir_name = argv[1];
    printf("%s\n", dir_name);
  }
  else
  {
    fprintf(stderr, "Too many arguments. Please provide only one directory name. Example: ./lsls <dir name>\n");
    exit(1);
  }
  // Open directory

  DIR *directory = opendir(dir_name);

  if (directory == NULL) // If there is an error, opendir() returns NULL
  {
    printf("Error incurred while opening directory.");
    exit(1);
  }

  // Repeatedly read and print entries
  struct dirent *entry;

  while ((entry = readdir(directory)) != NULL)
  {
     printf("  %s\n", entry->d_name);
  }
  
  // Close directory
  closedir(directory);
  return 0;
}