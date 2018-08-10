#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  struct dirent *newdir;
  struct stat buf;
  DIR *d;
  char *path;
  // Parse command line
  if (argc > 2) {
    fprintf(stderr, "Usage: ./lsls <directory name>(optional)\n");
    exit(1);
  } else if (argc == 2) {
    path = argv[1];
  } else {
    path = ".";
  }

  // Open directory
  d = opendir(path);
  if (d == NULL) {
    fprintf(stderr, "Error Opening Directory\n");
    exit(1);
  }

  // Repeatly read and print entries
  while ( (newdir = readdir(d)) != NULL ) {
    char buffer[256];
    snprintf(buffer, sizeof buffer, "%s%s%s", path, "/", newdir->d_name);
    stat(buffer, &buf);
    if (S_ISDIR(buf.st_mode)) {
      printf("%10s  ", "<DIR>");
    } else {
      printf("%10ld  ", buf.st_size);
    }
    printf("%s\n", newdir->d_name);
  }
  
  // Close directory
  closedir(d);

  return 0;
}