#include <stdio.h>
#include <dirent.h>
#include <string.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Pointer for directory entry
  struct dirent *de;
  char *path;
  // Parse command line

  // read input
  // fgets(commandline, sizeof(commandline), stdin);

  // Open directory
  if (argv[1] != NULL)
  {
    path = argv[1];
  }
  else
  {
    path = ".";
  }

  DIR *d = opendir(path);
  printf("Testing: %s\n", d == NULL ? "FAIL" : "PASS");
  printf("Testing path: %s\n", path);

  // Repeatly read and print entries
  // Repeatly read and print entries
  while ((de = readdir(d)) != NULL)
  {
    printf("%llu %s\n", de->d_ino, de->d_name);
  }

  // Close directory
  closedir(d);

  return 0;
}