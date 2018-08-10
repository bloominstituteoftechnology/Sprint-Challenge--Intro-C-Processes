#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

/**
 * Main
 */

int main(int argc, char **argv)
{
  // Parse command line
  if (argc > 2) {
    fprintf(stderr, "usage: lsls <optional: path>\n");
    exit(1);
  }

  char *path_to;

  if (argv[1]) {
    path_to = argv[1];
  } 
  else {
    path_to = ".";
  }

  // Open directory
  DIR *opened_dir = opendir(path_to);

  if (!opened_dir) {
    fprintf(stderr, "Path could not be found.\n");
    exit(1);
  }
  // Repeatly read and print entries
  struct dirent *currdir = readdir(opened_dir);
  struct stat buf;
  // Possibly overwrought string manipulation for path arg of stat()
  char path_str[255];
  char path_str_tosize[255];
  strcpy(path_str, path_to);
  strncat(path_str, "/", 2);
  printf("opened_dir: %s\n", (char*) path_str);
  
  while (currdir) {
    strcpy(path_str_tosize, path_str);
    strncat(path_str_tosize, currdir->d_name, 255 - strlen(path_str));

    stat(path_str_tosize, &buf);

    // printf("IFDIR result: %i\n", (int) S_ISDIR(buf.st_mode));

    if (S_ISDIR(buf.st_mode)) {
      printf("<DIR>\t\t%s\n", currdir->d_name);
    }
    else {
      printf("%ld\t\t%s\n", buf.st_size, currdir->d_name);
    }
    currdir = readdir(opened_dir);
  }

  // Close directory
  closedir(opened_dir);

  return 0;
}