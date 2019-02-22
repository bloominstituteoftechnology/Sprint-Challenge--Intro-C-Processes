#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{

  // printf("There are %d command line argument(s):\n", argc);

  // for (i = 0; i < argc; i++)
  // {
  //   // printf("   %s\n", argv[i]);
  //   // printf("Directory to visit: %s\n", argv[1]);
  // }

  // printf("Directory to visit: %s\n", argv[1]);
  // printf("Number of Command line args: %d\n", argc);

  // prints command line args info
  int i;
  printf("There are %d command line argument(s):\n", argc);

  for (i = 0; i < argc; i++)
  {
    printf("   %s\n", argv[i]);
  }

  // returns file size of directory
  struct stat buf;
  // stat(".", &buf);
  (argv > 1) ? stat(argv[1], &buf) : stat(".", &buf);
  printf("file size is %lld\n", buf.st_size);
  // argc > 1 ? printf("File size is %lld\n", buf.st_size);

  // opens directory passed in from command line
  DIR *d;
  struct dirent *dir;
  d = (argc > 1) ? opendir(argv[1]) : opendir(".");
  if (d)
  {
    while ((dir = readdir(d)) != NULL)
    {
      printf("%s\n", dir->d_name);
    }
    closedir(d);
  }
  return (0);
}