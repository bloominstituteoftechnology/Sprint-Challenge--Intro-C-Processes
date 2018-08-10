#include <stdio.h>
#include <dirent.h>
//#include <sys/types.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char *dirname;
  // if no additional arguments added, just print current dir
  if (argc == 1)
  {
    dirname = ".";
  }
  // if there is an argument, print that directory
  else if (argc == 2)
  {
    dirname = argv[1];
  }
  // otherwise, error - try again
  else
  {
    fprintf(stderr, "Try again - usage: './lsls (dirname)\n");
  }
  // Open directory
  struct dirent *dir;
  DIR *d = opendir(dirname);
  // Repeatly read and print entries
  if (d)
  {
    while ((dir = readdir(d)) != NULL)
    {
      printf("%s\n", dir->d_name);
    }
  // Close directory
    closedir(d);
  }
  return 0;
}
