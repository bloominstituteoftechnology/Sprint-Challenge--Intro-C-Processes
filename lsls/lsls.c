#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
   // Open directory
  /* check to make sure that proper arguments are being passed on the command line */

  struct dirent *Directory;
  struct stat buf; /* buffer variable from yesterday's examples */

  DIR *dir;
  
  if(argc < 2) {
    dir = opendir(".");
  }
  else {
    dir = opendir(argv[1]);
  }
  
  if(dir == NULL) {
    fprintf(stderr, "Please provide a directory!\n"); /* error handling for non-argument cases */
    exit(1);
  }
  // Repeatly read and print entries
  /* needs a loop to check that Directory is non-null */

  while((Directory = readdir(dir)) != NULL) {
    if(argc < 2) {
      stat(Directory->d_name, &buf); /* assign properties to Directory if an entry is found */
      printf("%101d %s\n", buf.st_size, Directory->d_name); /* return directory length and name */
    }
    else {
      char *path = malloc(strlen(argv[1] + strlen(Directory->d_name) + 2));
      sprintf(path, "%s%s", argv[1], Directory->d_name);
      stat(path, &buf);
      printf("%101d %s\n", buf.st_size, Directory->d_name);
      free(path);
    }
  }

  // Close directory
  closedir(dir);
  return 0;
}