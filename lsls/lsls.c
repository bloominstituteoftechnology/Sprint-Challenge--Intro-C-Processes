#include <stdio.h>
#include <dirent.h>
/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char *dir;

  if (argc == 2)
  {
    dir = argv[1];
  }
  else if (argc < 2)
  {
    dir = ".";
  }
  else if (argc > 2)
  {
    printf("Input Error, please specify path");
  }
  // Open directory
  DIR *d = opendir(dir);
  if (d == NULL)
  {
    printf("Error");
  }
  // Repeatly read and print entries
  // Close directory

  return 0;
}