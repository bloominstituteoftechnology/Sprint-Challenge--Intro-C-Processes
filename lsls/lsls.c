#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char *path = argv[1];
  printf("Arguments: %d\n", argc);
  printf("Path: %s\n", path);

  // Open directory
  DIR *directory = opendir(path);
  if (directory == NULL)
  {
    printf("Ups, there were an issue opening the directory. Try again");
    exit(1);
  }

  // Repeatly read and print entries
  struct dirent *entry;
  do
  {
    entry = readdir(directory);
    if (entry)
    {
      printf("%s\n", entry->d_name);
    }
  } while (entry != NULL);

  // Close directory
  closedir(directory);
  printf("END\n");

  return 0;
}