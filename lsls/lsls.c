#include <stdio.h>
#include <dirent.h>
#include <string.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line


  int show_hidden = 0;

  int my_path_index = 0;

  for (int i = 1; i < argc; i++) {
    if (!strcmp(argv[i], "-a")) {
      show_hidden = 1;
    }
    else {
      my_path_index = i;
    }

  }




  // Open directory

  DIR *directory;
  if (my_path_index) {
    directory = opendir(argv[my_path_index]);
  }
  else {
    directory = opendir(".");
  }

  // Repeatly read and print entries

  struct dirent *current_file;

  while ((current_file = readdir(directory)) != NULL) {
    if (show_hidden || current_file->d_name[0] != '.') {
      printf(" %s \n", current_file->d_name);
    }
  }

  // Close directory

  closedir (directory);

  return 0;
}