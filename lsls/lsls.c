#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  struct dirent *pDirent;
  DIR *open;
  struct stat tellsStats;

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
    stat(pDirent -> d_name, &tellsStats);
    if (tellsStats.st_mode & S_IFDIR) {
      printf("%16s  %s\n", "<DIR>", pDirent -> d_name);
    } else if (tellsStats.st_mode & S_IFREG) {
      printf("%16lld  %s\n", tellsStats.st_size, pDirent -> d_name);
    }
  }

  // Close directory
  closedir(open);
  return 0;
}