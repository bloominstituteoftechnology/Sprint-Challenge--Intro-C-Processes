#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char *path;
  if (argc > 1) {
    path = argv[1];
    fprintf(stderr, "Extra args.\n");
    exit(0);
  } else {
    path = ".";
  }
  
  // Open directory
  DIR *directory = opendir(path);
  if (directory == NULL) {
    fprintf(stderr, "Cannot open directory.\n");
    exit(1);
  } 

  // Repeatly read and print entries
  struct dirent *entries;
  struct stat buf;

  while ((entries = readdir(directory)) != NULL) {
    char *file_name = entries->d_name;
    stat(file_name, &buf);
    printf("%10lld  %s\n", buf.st_size, file_name);
  }

  // Close directory
  closedir(directory);

  return 0;
}