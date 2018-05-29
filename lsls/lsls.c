#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
/**
 * Main
 */
int main(int argc, char **argv) {


  printf("There are %d command line argument(s):\n", argc);
  for (int i = 0; i < argc; i++) {
    printf("   %s\n", argv[i]);
  }
  
  // Parse command line
  char *dir;

  if (argc == 1) {
    dir = ".";
  } else if (argc == 2) {
    dir = argv[1];
  } else {
    fprintf(stderr, "usage: ./lsls [dir]\n");
    exit(1);
  }
  // Open directory, opendir()
  DIR *d = opendir(dir);
  if (d == NULL) {
    
    fprintf(stderr, "lsls: unable to open directory %s, exiting\n", dir);
    exit(2);
  }

  // Repeatly read and print entries, readdir()
  struct dirent *ent;

  while ((ent = readdir(d)) != NULL) {
    // print the file and its size in bytes

    char fullpath[8192];
    struct stat stat_buf;

    // get the full path
    snprintf(fullpath, sizeof(fullpath), "%s/%s", dir, ent->d_name);

    // stat the given file to find the number of bytes it contains
    if (stat(fullpath, &stat_buf) == -1) {
      fprintf(stderr, "failed to stat file %s\n", fullpath);
      exit(3);
    }

    if (stat_buf.st_mode == S_IFREG) {
      // print the name of the file and its size
      printf("%10lld %s\n", stat_buf.st_size, ent->d_name); // 10's are for formatting
    } else if (stat_buf.st_mode == S_IFDIR) {
      // we have a directory; mark it
      printf("%10s %s\n", "<DIR>", ent->d_name);
    } else {
      printf("%10s %s\n", "", ent->d_name);
    }
  }

  // Close directory, closedir()
  closedir(d);

  return 0;
}