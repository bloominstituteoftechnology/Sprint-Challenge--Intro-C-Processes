#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  char *dir_name; // the dir we want to look into
  // Parse command line
  if (argc < 2)
  {
    dir_name = "."; // no specific dir, checking current dir
  }
  else if (argc == 2)
  {
    dir_name = argv[1]; //argv[0] = ls, argv[1] = dir name
  }
  else
  {
    printf("\nInvalid directory\n");
    exit(1);
  }
  // Open directory
  DIR *dir = opendir(dir_name);

  if (dir == NULL)
  {
    fprintf(stderr, "\nInvalid directory: %s\n", dir_name);
    exit(2);
  }
  // Repeatly read and print entries
  struct dirent *entry;

  while ((entry = readdir(dir)) != NULL)
  {
    struct stat buf;
    char file_path[1024];
    strcat(file_path, dir_name);
    strcat(file_path, "/");
    strcat(file_path, entry->d_name);

    stat(file_path, &buf);

    printf("\n%lld %s\n", buf.st_size, entry->d_name);
  }

  // Close directory
  closedir(dir);

  return 0;
}
