#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char* path;
  struct dirent *et;

  if(argc > 1) {
    path = argv[1];
  }
  else {
    path = ".";
  }
  // Open directory
  DIR *dr = opendir(path);
  // Repeatly read and print entries
  if(dr == NULL) {
    printf("Directory is null");
    exit(1);
  }
while((et = readdir(dr)) != NULL) {
    printf("%s\n", et->d_name);
  }
  // Close directory
  closedir(dr);

  return 0;
}