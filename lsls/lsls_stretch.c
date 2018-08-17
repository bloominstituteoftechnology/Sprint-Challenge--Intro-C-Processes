#include <stdio.h>
#include <dirent.h> // holds the declarations for DIR, struct dirent, opendir(), readdir(), and closedir()
#include <unistd.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *dir;
  struct dirent *ent;

  // Parse command line
  // If no directory is specified in command line, print instruction and exit process
  if (argc == 1)
  {
    printf("Please specify a directory name when running me such as: ./lsls [directory name]\n");
    exit(1);
  }

  // Open directory
  dir = opendir(argv[1]);

  if (dir != NULL)
  {
    // Repeatly read and print entries
    while ((ent = readdir(dir)) != NULL)
    {
      printf("%s\n", ent->d_name);
    }
  }
  else
  {
    printf("Directory opening error");
    exit(2);
  }
  // Close directory
  closedir(dir);

  return 0;
}