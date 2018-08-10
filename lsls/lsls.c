#include <stdio.h>
#include <dirent.h>
#include <string.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line


  char show_hidden = 0;

  char my_path_index = 0;

  char show_size = 0;



  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-') {
      int j = 1;
      while (argv[i][j] != NULL) {
        if (argv[i][j] == 'a') {
          show_hidden = 1;
        }
        else if (argv[i][j] == 'l') {
          show_size = 1;
        }
        j++;
      }
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
      if (show_size) {
        printf(" size_placeholder ");
      }
      printf(" %s \n", current_file->d_name);
    }
  }

  // Close directory

  closedir (directory);

  return 0;
}