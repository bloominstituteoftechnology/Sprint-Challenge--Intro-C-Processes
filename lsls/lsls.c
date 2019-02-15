#include <stdio.h>
#include <dirent.h> //includes DIR, struct dirent, opendir(), readdir(), and closedir()
#include <sys/stat.h> //includes stat() to be used to get size of entries

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  // Open directory - opendir()
  // Repeatly read and print entries - readdir()
  // Close directory - closedir()

  DIR *dir;
  struct dirent *dirent;
  struct stat filesize;

  if (argc > 2)
    {
      printf("Openning...\n");
      dir = opendir(argv[1]);
    }
  else if (argc < 2)
  {
    printf("There was no specified directory, printing content from '.' directory.\n");
    dir = opendir(".");
  }
  else
  {
    if (dir == NULL)
    {
      printf("Cannot open directory '%s'.\n", argv[1]);
      exit(1);
    }
  }

  while ((dirent = readdir(dir)) != NULL)
  {
    stat("./lsls.c", &filesize);
    printf("File Size: %lld bytes - Directory: %s\n", filesize.st_size, dirent->d_name);
  }

  closedir(dir);
  return 0;
}

