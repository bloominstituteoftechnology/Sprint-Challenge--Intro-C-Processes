#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  struct dirent *pDirent;
  DIR *open;

  // Parse command line
  if (argv[1] == NULL) {
    argv[1] = ".";
  }
  char* currentDir[] = { "ls", argv[1], NULL };

  // Open directory
  open = opendir(currentDir[1]);
  if (open == NULL) {
    fprintf (stderr, "cannot print\n");
    return 1;
  }

  // Repeatly read and print entries
  while ((pDirent = readdir(open)) != NULL) {
    printf("%s\n", pDirent -> d_name);
  }

  // Close directory
  closedir(open);
  return 0;
}