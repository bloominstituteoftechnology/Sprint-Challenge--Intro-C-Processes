#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  struct dirent *de;
  DIR *d;


  // Open directory
  if (argv[1] != '\0' && argc >= 2)
  {
    d = opendir(argv[1]);
  }
  else
  {
    d = opendir(".");
  }
  // Repeatly read and print entries, calling readdir until it is NULL
  while ((de = readdir(d)) != NULL){
    printf("%s\n", de->d_name);
  }


// Close directory
closedir(d);
return 0;
}