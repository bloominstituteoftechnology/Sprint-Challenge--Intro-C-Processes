#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{

  DIR *dir;
  struct dirent *dent;
  // Parse command line
  // printf("There are %d command line argument(s):\n", argc);
  for (int i = 0; i < argc; i++)
  {
    printf("   %s\n", argv[i]);
    // char *dir = opendir(argv[1]);
    dir = opendir(argv[1]);
    // Open directory
  }
  if (dir != NULL)
  {
    while ((dent = readdir(dir)) != NULL)
      // Repeatly read and print entries
      printf("[%s]\n", dent->d_name);
  }
  // Close directory
  closedir(dir);

  return 0;
}