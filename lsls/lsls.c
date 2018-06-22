#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  struct dirent *dir;
  char *directName;
  if (argc == 1) {
    directName = ".";
  } else if (argc == 2) {
    directName = argv[1];
  } else {
    fprintf(stderr, "./lsls [directName]\n");
  }

  DIR *d = opendir(directName);
  if (d == NULL) {
    printf("Could not open current directory\n");
    return 0;
  }
  while ((dir = readdir(d)) != NULL) {
    printf("%s\n", dir->d_name);
  }
  closedir(d);
  return 0;
}