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
  if (argc == 1)
  {
    printf("Please specify a directory name when running me\n");
    exit(1);
  }

  // Open directory
  for (int i = 0; i < argc; i++)
  {
    // printf(" %s\n", argv[i]);
    dir = opendir(argv[i]);
  }

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