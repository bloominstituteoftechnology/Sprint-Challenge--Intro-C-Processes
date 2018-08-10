#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char *directory_name;
  if (argc == 1)
  {
    directory_name = ".";
  }
  else if (argc == 2)
  {
    directory_name = argv[1];
  }
  else
  {
    fprintf(stderr, "Too amny arguments! Usage: ./index2 [your directory name]\n");
    exit(1);
  }

  // Open directory
  struct dirent *ent;
  
  
  DIR *directory = opendir(directory_name);
  
  if (directory == NULL)
  {
    fprintf(stderr, "The directory open error");
    exit(2);
  }

  // Repeatly read and print entries
  while ((ent = readdir(directory)) != NULL)
  {
    char path[200];
    struct stat buf;
    
    snprintf(path, sizeof(path), "%s/%s", directory_name, ent->d_name);
    stat(path, &buf);
    printf("%20lld %s\n", buf.st_size, path);
  }

  // Close directory
  closedir(directory);
  return 0;
}