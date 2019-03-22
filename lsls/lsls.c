#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  int i;
  for (i = 0; i < argc; i++)
  {
    printf("   %s\n", argv[i]);
  }

  // file size of directory
  struct stat buf;
  (argv > 1) ? stat(argv[1], &buf) : stat(".", &buf);
  printf("file size is %lld\n", buf.st_size);

  DIR *d;
  struct dirent *dir;

  // Open directory

  // Repeatly read and print entries

  // Close directory

  return 0;
}