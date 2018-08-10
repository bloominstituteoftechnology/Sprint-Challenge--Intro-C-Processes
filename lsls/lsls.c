#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>

// Lookup

  void lookup(const char *arg) {
  // Open directory
  DIR *dir;
  struct dirent *dp;

  if ((dir = opendir(".")) == NULL)
  {
    perror("Cannot open directory\n");
    exit(1);
  }
  // Repeatly read and print entries

  do
  {
    errno = 0;

    if ((dp = readdir(dir)) != NULL)
    {

      if (strcmp(dp->d_name, arg) != 0)
      {
        continue;
        printf("yay its printing\n");
        printf("%s\n", arg);
        closedir(dir);
      }
    }

  } while (dp != NULL);

  
  if (errno != 0) {
    printf("Error reading dirs");
  }
  else {
    printf("%s not found\n", arg);
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
    lookup(argv[i]);
  }

  return 0;
}