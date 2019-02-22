#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Define pointers
  DIR *directory;
  struct dirent *entry;
  struct stat buf;

  // Parse command line and Open directory
  directory = (argc > 1) ? opendir(argv[1]) : opendir(".");

  if (directory == NULL)
  {
    fprintf(stderr, "Error opening directory");
    return 0;
  }

  // Repeatedly read and print entries
  while ((entry = readdir(directory)) != NULL)
  {
    stat(entry->d_name, &buf);
    printf("%10llu --- %s\n", buf.st_size, entry->d_name);
  }

  // Close directory
  closedir(directory);

  return 0;
}