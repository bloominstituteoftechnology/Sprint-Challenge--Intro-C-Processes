#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line

  // Open directory
  struct dirent *de;
 
  DIR *dr = opendir(((argc == 1 ) ? (".") : (argv[1])));
 
  if (dr == NULL)
  {
    printf("Could not open directory\n");
    return 0;
  }

  // Repeatly read and print entries
 
  while ((de = readdir(dr)) != NULL)
  {
    printf("%s\n", de->d_name);
  }

  // Close directory  
  closedir(dr);    

  return 0;
}
