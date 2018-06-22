#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // pointer for directory entry
  struct dirent *de;

  // opendir() returns pointer of DIR type
  DIR *d = opendir(".");
  // opendir returns NULL if couldn't open directory
  if (d == NULL)
  {
    printf("Could not open current directory");

    return 0;
  }
  // readdir() returns a pointer to a structure representing a directory entry at the current position specified by dr
  while ((de = readdir(d)) != NULL)
  {
    printf("%s\n", de->d_name);
  }

  closedir(d);
  return 0;
}