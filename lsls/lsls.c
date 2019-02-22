#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <errno.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  // Print current dir entries
  struct dirent *Dirent;
  DIR *dir;
  if (argc < 2)
  {
    dir = opendir(".");
  }
  else
  {
    dir = opendir(argv[1]);
  }

  if (dir == NULL)
  {
    printf("%d\n", errno);
    exit(1);
  }
  while ((Dirent = readdir(dir)) != NULL) 
  {
    printf ("%s\n", Dirent->d_name);
  }
  closedir(dir);
	
    // Print argv[1] entries
    
  
  
  // Open directory

  // Repeatly read and print entries

  // Close directory

  return 0;
}