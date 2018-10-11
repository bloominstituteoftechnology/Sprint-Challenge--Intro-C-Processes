#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  
  struct dirent *dr;
  DIR *dir;
  // Parse command line
  if (argc > 2) {
    dir = opendir(argv[1]);
  }
    else{
    dir = opendir(".");
    }
  // Repeatly read and print entries
  if (dir == NULL) {
    printf("error\n");
    exit(1);
  }
  while(( dr = readdir(dir))!= NULL)
    printf("%s\n", dr->d_name);
  // Close directory
  closedir(dir);
  return 0;
}