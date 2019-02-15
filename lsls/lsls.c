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

  struct dirent *dirName;
  struct stat buffer;
  char *dirPath;
  char *filePathInfo;
  DIR *dir;

  // Parse command line
  if (argc > 1) {
    dirPath = argv[1];
  } else {
    dirPath = ".";
  } 

  // Open directory
  if ((dir = opendir(dirPath)) == NULL) {
    printf("Invalid directory: %s\n", dirPath);
    exit(1);
  }

  // Repeatedly read and print entries:
  while((dirName = readdir(dir)) != NULL) {

    filePathInfo = malloc(strlen(dirPath) + strlen(dirName -> d_name) + 2);

    if (strcmp(dirName -> d_name, ".") != 0 && strcmp(dirName -> d_name, "..") != 0) {
      sprintf(filePathInfo, "%s/%s", dirPath, dirName -> d_name);
    } else {
      sprintf(filePathInfo, "%s", dirName -> d_name);
    }

    // Print properties of the file as well if accessible
    if (stat(filePathInfo, &buffer) != -1) {
      if(buffer.st_mode == 16895) {
        printf("<DIR> %s\n", dirName -> d_name);
      } else {
        printf("%10ld %s\n", buffer.st_size, dirName -> d_name);
      }     
    }
    ////

    free(filePathInfo);

  }

  // Close directory

  return 0;
}