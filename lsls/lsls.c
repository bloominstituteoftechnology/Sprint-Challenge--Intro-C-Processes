#include <stdio.h>
#include <dirent.h>


/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char *path;
  if (argc == 1) {
    path = ".";
  } else {
    path = argv[1];
  }
  // Open directory
  DIR *d = opendir(path);
  // Repeatly read and print entries
  struct dirent *f;
  while ((f = readdir(d)) != NULL) {
    printf("%s\n", f->d_name);
  }
  // Close directory
  closedir(d);

  return 0;
