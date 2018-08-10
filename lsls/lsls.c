#include <stdio.h>
#include <dirent.h>

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

  // Repeatly read and print entries

  // Close directory

  return 0;
}