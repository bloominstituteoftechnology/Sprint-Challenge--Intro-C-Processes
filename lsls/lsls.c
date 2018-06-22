#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *dir;
  struct dirent *direntry;

  // Get directory from argument (default to `.`)
  char *dirname = argc == 2 ? argv[1] : ".";

  // Open directory 
  if ((dir = opendir(dirname)) == NULL)
  {
    printf("Cannot open directory %s\n", dirname);
    exit(1);
  }

  // Repeatly read and print entries
  while ((direntry = readdir(dir)) != NULL)
  {
    puts(direntry->d_name);
  }

  // Close directory
  closedir(dir);
  return 0;
}