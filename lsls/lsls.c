#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  struct dirent *entry;
  DIR *dir;

  if (argc < 2) {
    dir = opendir(".");
  } else if (argc > 2) {
    printf("You've entered more arguments than expected!");
    exit(1);
  } else {
    dir = opendir(argv[1]);
  }

  if (dir == NULL) {
    printf("Error, no directory found\n");
    exit(1);
  }

  while ((entry = readdir(dir)) != NULL) {
    if (argc < 2) {
      printf("./%s\n", entry->d_name);
    } else {
      printf("%s\n", entry->d_name);
    }
  }

  closedir(dir);
  
  return 0;
}