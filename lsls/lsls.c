#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <errno.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line

  // Open directory

  DIR *directory = opendir(".");
  struct dirent   *directory_entry;
  int i;

  printf("Testing: %s\n", directory == NULL? "FAIL": "PASS");

  // Repeatly read and print entries
  while ((directory_entry = readdir(directory)) != NULL)
  {
    i++;
    printf("\n%s", directory_entry->d_name);
  }

  // Close directory

    closedir(directory);

  return 0;
}