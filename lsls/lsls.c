#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

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
    fprintf(stderr, "usage: ./lsls [dirname]\n");
    exit(1);
  }
  // Open directory
  DIR *d = opendir(dirname);
  //Error check for dir opening
  if (d == NULL) {
    fprintf(stderr, "./lsls: cannot open directory %s\n", dirname);
    exit(2);
  }
  // Repeatly read and print entries
  struct dirent *entry;

  while ((entry = readdir(d))!=NULL) {
    char path[8196];
    struct stat stat_buf;

    snprintf(path, sizeof(path), "%s/%s", dirname, entry->d_name);
  
    if (stat(path, &stat_buf) < 0) {
      fprintf(stderr, "failed to stat file %s\n", path);
      exit(3);
    }

    if (S_ISREG(stat_buf.st_mode)) {
      printf("%10lld      %s\n", stat_buf.st_size, entry->d_name);
    } else if (S_ISDIR(stat_buf.st_mode)) {
      printf("%10s     %s\n", "<DIR>", entry->d_name);
    } else {
      printf("%10s     %s\n", "", entry->d_name);
    }
  }
  // Close directory
  closedir(d);

  return 0;
}