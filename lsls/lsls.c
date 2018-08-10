#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>

// List

  void list(const char *arg) {
  // Open directory
  DIR *dir;
  struct dirent *dp;
  struct stat buf;

  if ((dir = opendir(arg)) == NULL)
  {
    perror("Cannot open directory\n");
    exit(1);
    return;
  }
  // Repeatly read and print entries

  
  while((dp = readdir(dir)) != NULL){
    errno = 0;
    if (errno != 0) {
      perror("Error reading dirs");
    }
    int size = stat(dp->d_name, &buf);
    printf("size: %10lld file -> %s\n", buf.st_size, dp->d_name);
  }
  
  closedir(dir);

  
  
  return;
}


/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  
  for(int i = 1; i < argc; i++)
  {
    list(argv[i]);
  }

  return 0;
}