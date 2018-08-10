#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Define pointers
  DIR *pDir;
  struct dirent *ent;
  struct stat buf;
  
  // Parse command line and Open directory
  pDir = (argc > 1) ? opendir(argv[1]) : opendir(".");

  if (pDir == NULL) {
    fprintf(stderr, "Error opening directory");
    return 0;
  }

  // Repeatedly read and print entries
  while ((ent = readdir(pDir)) != NULL) {
    stat(ent->d_name, &buf);
    printf("%10llu --- %s\n", buf.st_size, ent->d_name);
  }

  // Close directory
  closedir(pDir);

  return 0;
}