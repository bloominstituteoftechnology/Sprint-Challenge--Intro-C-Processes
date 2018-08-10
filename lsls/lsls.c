#include <stdio.h>
#include <dirent.h>

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
  }

  // Open directory
  DIR *opened_dir = opendir(dir_path);
  struct dirent *dir;

  // Repeatly read and print entries
  if (opened_dir) {
    while((dir = readdir(opened_dir)) != NULL) {
      printf("%s\n", dir->d_name);
    }
      // Close directory
    closedir(opened_dir);
  }

  return 0;
}