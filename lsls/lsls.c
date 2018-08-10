#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */

/*The opendir() function opens a directory stream corresponding to the directory name, 
and returns a pointer to the directory stream. The stream is positioned at the first 
entry in the directory.*/

int main(int argc, char **argv)
{
  // Parse command line
  // Open directory

  // The DIR data type represents a directory stream. It's declared in the header `dirent.h`
  DIR *d;
  struct dirent *dir;
  d = opendir("."); 

  // Repeatly read and print entries
  // If find NULL, means no content in that dir
  if(d)
  {
    while((dir = readdir(d)) != NULL)
    {
      printf("%s\n", dir ->d_name);
    }

  // Close directory
  closedir(d);
  }

  return 0;
}