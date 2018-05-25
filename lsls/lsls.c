#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line

  int i;
  struct dirent *pDirent;
  DIR *pDir;

  {
    printf("Usage: testprogram\n");
    exit(1);
  }

  // Open directory

  pDir = opendir(**argv);
  if (pDir == NULL)
  {
    printf("Cannot open directory '%s'\n", **argv);
    exit(1);

    // Repeatly read and print entries
  }
  while ((pDirent = readdir(pDir)) != NULL)
  {
    printf("[%s]\n", pDirent->d_name);
  }

  // Close directory

  closedir(pDir);
  return 0;
}