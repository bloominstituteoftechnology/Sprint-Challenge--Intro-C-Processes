#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char *dirname;

  if (argc == 1)
  {
    dirname = ".";
  }
  else if (argc == 2)
  {
    dirname = argv[1];
  }
  else
  {
    fprintf(stderr, "Usage: ./lsls [dirname]\n");
  }

  // Open directory
  DIR *d = opendir(dirname);

  // error check
  if (d == NULL)
  {
    fprintf(stderr, "lsls: cannot open directory %s\n", dirname);
  }

  struct dirent *ent;

  // Repeatly read and print entries
  while ((ent = readdir(d)) != NULL)
  {
    printf("%s\n", ent->d_name);
  }
  // Close directory
  closedir(d);
  return 0;
}