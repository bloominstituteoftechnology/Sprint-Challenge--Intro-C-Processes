#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  struct dirent *ent;

    char *next;
  if(argc == 1) {
    next = ".";
  }

  else {
    next = argv[1];
  }

  // Open directory

  DIR *d = opendir(next);

  // Repeatly read and print entries

  if(d == NULL) {
    printf("NULL");
    return 0;
  }

  else {
    while((ent = readdir(d)) != NULL) {
      printf("%s\n", ent->d_name);
    }
  }

  // Close directory

  closedir(d);

  return 0;
}