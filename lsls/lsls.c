#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv){
  DIR *w_dir;
  // Parse command line
  int count;
    for (count=0; count<argc; count++)
        puts (argv[count]);

  // Open directory
  w_dir = opendir(argv[1]);

  // Repeatly read and print entries


  // Close directory
  closedir(w_dir);

  return 0;
}