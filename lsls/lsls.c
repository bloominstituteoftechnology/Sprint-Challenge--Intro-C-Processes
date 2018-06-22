#include <stdio.h>
#include <dirent.h>
#include <string.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  DIR *dir;
  struct dirent *ent;
  dir = opendir(argv[1]);

  // Open directory
  ent = readdir(dir);

  // Repeatly read and print entries
  if (dir != NULL) {
    while(ent != NULL) {
      if((strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0 || (*ent->d_name) == '.')) {

      } else {
        printf("%s\n", ent->d_name);
      }
    }
    close(dir);
  }

  // Close directory

  return 0;
}