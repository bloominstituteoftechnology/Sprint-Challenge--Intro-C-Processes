#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  DIR *dir;
  struct dirent *ent;
  char *filename = ".";

  // Open directory
  //checks if a directory has been passed
  if (argc == 2)
  {
    filename = argv[1];
  }

  if ((dir = opendir(filename)) == NULL) {
    printf (stderr, "An error happened while trying to read the file directory. Try again! \n");
    exit(1);
  }


  // Repeatly read and print entries

  while ((ent = readdir(dir)) != NULL)
  {
    printf("%s\n", ent->d_name);
  }

  // Close directory

  closedir(dir);

  return 0;
}