#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *d;
  char *directory;
  struct dirent *ent;
  ;
  // Parse command line
  if (argc > 1)
  {
    printf("more than one command!\n");
    directory = argv[1];
  }

  // Open directory
  if (directory)
  {
    d = opendir(directory);
  }
  else
  {
    d = opendir(".");
  }

  // Repeatly read and print entries

  if (d == NULL)
  {
    fprintf(stderr, "open directory error\n");
    exit(1);
  }

  //printf("%s\n", ent->d_name);
  while ((ent = readdir(d)) != NULL)
  {
    printf("%s\n", ent->d_name);
  }
  //Close directory
  closedir(d);

  return 0;
}