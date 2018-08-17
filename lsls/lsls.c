#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char *directory;
  struct stat statbuf;
  char *dir = "<DIR>";
  if (argc > 1)
    directory = argv[1];
  else
    directory = ".";
  printf("%s\n", directory);
  // Open directory
  DIR *target = opendir(directory);
  if (target == NULL)
  {
    printf("%s\n", "Cannot open directory");
    exit(1);
  }
  // Repeatly read and print entries
  struct dirent *entry;
  while (entry = readdir(target))
  {
    stat(entry->d_name, &statbuf);
    if (statbuf.st_size != 0)
      printf("%10lld %s\n", statbuf.st_size, entry->d_name);
    else
      printf("%10lls %s\n", dir, entry->d_name);
  }
  // Close directory
  closedir(target);
  return 0;
}