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
  char *path;
  if (argc > 1)
  {
    path = argv[1];
  }
  else
  {
    path = "./";
  }

  // Open directory
  DIR *dir;
  dir = opendir(path);

  // Check to see if the directory could not be opened.
  if (dir == NULL)
  {
    printf("Error: Could not open directory. \n");
    exit(1);
  }

  // Repeatly read and print entries
  struct dirent *current_dir = readdir(dir);
  while (current_dir)
  {
    struct stat buf;

    printf("%s/%s", path, current_dir->d_name);
    stat(path, &buf);

    printf("%10lld %s\n", buf.st_size, current_dir->d_name);
    current_dir = readdir(dir);
  }

  // Close directory
  closedir(dir);

  return 0;
}