#include <stdio.h>
#include <dirent.h>
#include <unistd.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  struct dirent *pDirent;
  DIR *open;
  char* currentDir[] = { "ls", ".", NULL };

  // Parse command line
  
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