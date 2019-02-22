#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char *path = argv[1] != NULL ? argv[1] : ".";
  //Open directory
  DIR *dir = opendir(path);
  // Repeatly read and print entries
  struct dirent *ent;
  while ((ent = readdir(dir)) != NULL){
    char *name = ent->d_name;
    char directory[strlen(path) + strlen(name)];
    strcpy(directory, path);
    strcat(directory, "/");
    strcat(directory, name);

    struct stat buf;
    stat(directory, &buf);
    printf("%ld %s\n", buf.st_size, name);
  }
  // Close directory
  closedir(dir);
  return 0;
}