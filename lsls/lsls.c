#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  char *directory;
  ;
  // Parse command line
  if (argc > 1)
  {
    printf("more than one command!\n");
    directory = argv[1];
  }

  // Open directory
  DIR *d;
  if (directory)
  {
    d = opendir(directory);
  }
  else
  {
    d = opendir(".");
  }

  // Repeatly read and print entries
  //dirent = readdir(d);
  while (ent != NULL)
    // {
    //   printf("%s", ent->d_name);
    // }
    // Close directory

    return 0;
}