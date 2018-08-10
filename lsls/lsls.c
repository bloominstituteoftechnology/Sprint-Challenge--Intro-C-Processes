#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  printf("\nSTART\n");

  // Parse command line
  char *path = argv[1];
  printf("Arguments: %d\n", argc);
  printf("Path: %s\n\n", path);

  // Open directory
  DIR *directory = opendir(path);
  if (directory == NULL)
  {
    printf("Ups, there were an issue opening the directory. Try again\n");
    exit(1);
  }

  // Repeatly read and print entries
  struct dirent *entry;
  printf("\tbytes\tDir/File\n");
  printf("\t-----\t--------\n");
  do
  {
    entry = readdir(directory);
    if (entry)
    {
      struct stat st;
      // FILE *file = fopen(entry->d_name, "r+");
      stat(entry->d_name, &st);
      printf("\t%lld\t%s\n", st.st_size, entry->d_name);
    }
  } while (entry != NULL);

  // Close directory
  closedir(directory);
  printf("END\n\n\n");

  return 0;
}