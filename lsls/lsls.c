#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  char *dirr;
  // Parse command line
  if (argc == 1)
  {
    dirr = ".";
  }
  else
  {
    dirr = argv[1];
  }
  // Open directory
  DIR *dirp = opendir(dirr);
  if (dirp == NULL)
  {
    printf("Can't open that");
  }
  // Repeatly read and print entries
  struct dirent *dent;
  struct stat fstats;
  dent = readdir(dirp);
  while(dent != NULL)
  {
    stat(dent->d_name, &fstats);
    printf("%d ----- %s", fstats.st_size, dent->d_name);
  }
  // Close directory
  closedir(dirp);
  return 0;
}