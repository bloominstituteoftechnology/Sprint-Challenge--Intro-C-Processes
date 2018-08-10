#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
// For TERMINAL 'man opendir'
/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  // \/\/ This?
  DIR *dir;
  struct dirent *ent;

  // Open directory
  dir = opendir(".");

  // Check directory exists
  if(dir == NULL)
  {
    printf("Error! Cannot open directory\n");
    exit(1);
  }

  // Repeatly read and print entries
  while( (ent=readdir(dir)) != NULL )
  {
    printf(">> %s\n", ent->d_name);
  }

  //
  if(ent=readdir(dir) == NULL)
  {
    return NULL;
  }

  // Close directory
  closedir(dir);
  return 0;
}
