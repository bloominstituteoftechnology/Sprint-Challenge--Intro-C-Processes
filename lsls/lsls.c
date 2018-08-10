#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Define pointers
  DIR *pDir;
  struct dirent *ent;
  
  // Parse command line and Open directory
  pDir = (argc > 1) ? opendir(argv[1]) : opendir(".");

  if (pDir == NULL) {
    fprintf(stderr, "Error opening directory");
    return 0;
  }

  // Repeatedly read and print entries
  while ((ent = readdir(pDir)) != NULL) {
    printf("%s\n", ent->d_name);
  }

  // Close directory
  closedir(pDir);

  return 0;
}