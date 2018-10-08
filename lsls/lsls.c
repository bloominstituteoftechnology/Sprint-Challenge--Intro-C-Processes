#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
DIR *dir;
struct dirent *dp;

  if ( argc == 1 ) {
    dir = opendir(".");
    while((dp = readdir(dir)) != NULL) {
      printf("%s\n", dp->d_name);
    }
    closedir(dir);

  }

  if( argc == 2 ) {
  dir = opendir(argv[1]);
  if (dir != NULL) {
   while((dp = readdir(dir)) != NULL) {
      printf("%s\n", dp->d_name);
    }
    closedir(dir);

  }
  }


  return 0;
}