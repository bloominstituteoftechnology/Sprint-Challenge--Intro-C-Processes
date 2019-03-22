#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char *dir_name;
  DIR *od;
  struct dirent *enter;
  struct stat fileStat;

  // Open directory

  // check if no input
  if (argc <= 1)
  {
    // print current directory
    dir_name = ".";
  }
  // if directory in input (argv[1]), make a ref to it
  else if (argc == 2)
  {
    dir_name = argv[1];
  }
  // catch any errors or incorrect directories
  else
  {
    printf("Cannot open dir '%s'!!", argv[1]);
  }

  // Open directory

  od = opendir(dir_name);

  // Repeatly read and print entries
  while ((enter = readdir(od)) != NULL)
  {
    stat(enter->d_name, &fileStat);

    if (fileStat.st_mode & S_IFDIR)
    {
      printf("%s\n", enter->d_name);
    }
    else
    {
      printf("size: %ldkb\t file: %s\n", fileStat.st_size, enter->d_name);
    }
  }

  // Close directory
  closedir(od);

  return 0;
}