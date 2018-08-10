#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>


void ls_directory(const char *directory_name)
{
  DIR *directory;
  struct dirent *entry;

  // Open directory
  directory = opendir(directory_name);
  if (directory != NULL)
  {
      // Repeatly read and print entries
    while ((entry = readdir(directory)) != NULL)
    {
      printf("%s\n", entry->d_name);
    }
  // Close directory
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