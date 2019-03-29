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
  d = (argc > 1) ? opendir(argv[1]) : opendir(".");
  if (d)
  {

    // Repeatly read and print entries
    while ((dir = readdir(d)) != NULL)
    {
      printf("%s\n", dir->d_name);
    }

  // Close directory
   if (closedir(d) == -1)
    {
      perror("closedir");
      return 0;
    }
  }

  return 0;
}