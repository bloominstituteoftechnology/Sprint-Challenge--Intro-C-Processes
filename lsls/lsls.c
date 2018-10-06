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
  if (argc < 1) {
    //if parameter holds more than 1 argument open?
  // Open directory
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