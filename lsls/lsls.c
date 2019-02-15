#include <stdio.h>
#include <dirent.h>
#include <unistd.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line

  // Open directory
  DIR *d = opendir(argv[1] ? argv[1] : ".");

  // Repeatly read and print entries
  struct dirent *entry;
  while ((entry = readdir(d)) != NULL)
  {
    printf("%lu %s\n", entry->d_ino, entry->d_name);
  }

  // Close directory
  closedir(d);

  return 0;
}