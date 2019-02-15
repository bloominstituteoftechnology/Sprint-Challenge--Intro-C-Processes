#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char *directory = argv[1] ? argv[1] : ".";

  //Open directory
  DIR *d = opendir(directory);

  // Repeatly read and print entries
  struct dirent *entry;
  while ((entry = readdir(d)) != NULL)
  {
    char *name = entry->d_name;
    char *path = malloc(strlen(directory) + strlen(name) + 1);

    strcpy(path, directory);
    strcat(path, "/");
    strcat(path, name);

    struct stat buf;
    stat(path, &buf);

    printf("%s:\n", path);
    printf("%10ld %s\n", buf.st_size, name);
  }

  // Close directory
  closedir(d);

  return 0;
}