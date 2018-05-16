#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

#define STRETCH_GOAL 1 // Define to 1 to enable stretch goal functionality

#if STRETCH_GOAL
#include <sys/stat.h>
#endif

/**
 * Main
 */
int main(int argc, char **argv)
{
  char *dirname;
  // Parse command line
  if (argc == 1) {
    dirname = ".";
  } else if (argc == 2) {
    dirname = argv[1];
  } else {
    fprintf(stderr, "usage: lsls [dirname]\n");
    exit(1);
  }

  // Open directory
  DIR *d = opendir(dirname);

  if (d == NULL) {
    fprintf(stderr, "lsls: cannot open directory %s\n", dirname);
    exit(2);
  }

  // Repeatly read and print entries
  struct dirent *entry;

  while ((entry = readdir(d)) != NULL) {
    #if STRETCH_GOAL
    char path[8192];
    struct stat stat_buf;

    // Get the full path
    snprintf(path, sizeof(path), "%s/%s", dirname, entry->d_name);

    if (stat(path, &stat_buf) == -1) {
      fprintf(stderr, "Failed to stat file %s\n", path);
      exit(3);
    }

    switch(stat_buf.st_mode & S_IFMT) {
      case S_IFREG:
        printf("%10lld  %s\n", stat_buf.st_size, entry->d_name);
        break;
      case S_IFDIR:
        printf("%10s  %s\n", "<DIR>", entry->d_name);
        break;
      default:
        printf("%10s  %s\n", "", entry->d_name);
        break;
    }
    #else
    printf("%s\n", entry->d_name);
    #endif
  }

  // Close directory
  closedir(d);

  return 0;
}