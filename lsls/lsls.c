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
    stat(dp->d_name, &buf);
    int size = buf.st_size;
    // printf("%d\n", size);
  
    
    if (size == 160 || size == 192) {
      printf("size: <DIR> file -> %s\n", dp->d_name);
    } else {
      printf("size: %10d file -> %s\n", size, dp->d_name);
    }
    
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