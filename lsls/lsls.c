#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char *dir_path;

  if (argc == 1) {
    dir_path = '.';
  } else if ( argc == 2) {
    dir_path = argv[1];
  } else {
    fprintf(stderr, "To execute file, run in this format: './lsls <directory-name>' \n");
    exit(1);
  }

  // Open directory
  DIR *opened_dir = opendir(dir_path);
  struct dirent *dir;

  // Repeatly read and print entries
  if (opened_dir) {
    while((dir = readdir(opened_dir)) != NULL) {
      struct stat filesize;
      if (stat(dir->d_name, &filesize) < 0) {
        fprintf(stderr, "Can't read stat of file\n");
        exit(2);
      }
      if (filesize.st_mode && __S_IFREG) {
        printf("%d %s\n", filesize.st_size, dir->d_name);
      } else {
        printf("%s\n", dir->d_name);
      }
    }
      // Close directory
    closedir(opened_dir);
  }

  return 0;
}