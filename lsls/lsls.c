#include <stdio.h>
#include <dirent.h>

// opendir()
// readdir()
// strcat()
// closedir()

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *dir;
  struct dirent *entry;
  dir = opendir(".");

  // Parse command line

  // Open directory
  if (dir == NULL)
  {
    printf(stderr, "Cannot open dir\n");
    exit(1);
  }

  // Repeatly read and print entries
  if (dir)
  {
    while ((entry = readdir(dir)) != NULL)
    {
      printf("%s\n", entry->d_name);
    }
    closedir(dir); // Close directory
  }
  return 0;
}
