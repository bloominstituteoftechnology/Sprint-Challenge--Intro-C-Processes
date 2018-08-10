#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *dir;
  struct stat st;
  struct dirent *dent;

  if (argc < 2)
  {
    printf("enter a directory \n");
    exit(1);
  }
  // Parse command line
  for (int i = 0; i < argc; i++)
  {
    // Open directory
    dir = opendir(argv[i]);
  }

  if (dir != NULL)
  {
    while ((dent = readdir(dir)) != NULL)
    {
      // Repeatly read and print entries
      if (dent->d_type == DT_DIR)
      {
        dent->d_type = 'd';
      }
      printf("%s\t\t %d\t\t %d\t\t \n", dent->d_name, dent->d_reclen, dent->d_type);
    }
  }

  // Close directory
  closedir(dir);

  return 0;
}