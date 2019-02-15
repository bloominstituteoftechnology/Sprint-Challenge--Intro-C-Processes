#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char *path;
  // Check for empty command line
  if (argc > 1) {
    path = argv[1];
  } else {
    path = ".";
  } 

  // Open directory
  DIR *directory = opendir(path);
  // Check if directory could not be opened.
  if (directory == NULL) {
    printf("Directory could not be opened: %s\n", path);
    exit(1);
  }

  // Repeatly read and print entries
  struct dirent *name;
  struct stat buffer;
  char *filepath; 
 
  while((name = readdir(directory)) != NULL) {
    filepath = malloc(strlen(path) + strlen(name -> d_name) + 1);

    if (strcmp(name -> d_name, ".") != 0 && strcmp(name -> d_name, "..") != 0) {
      sprintf(filepath, "%s/%s", path, name -> d_name);
    } else {
      sprintf(filepath, "%s", name -> d_name);
    }

    stat(filepath, &buffer);

    printf("%10ld %s\n", buffer.st_size, name -> d_name);
    free(filepath);
  }

  // Close directory

  return 0;
}