#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line

  // Open directory
  struct dirent *de;
  DIR *dr = opendir(".");

  if (dr == NULL)  // opendir returns NULL if couldn't open directory
    {
        printf("Could not open current directory.\n" );
        exit(1);
    }

  // Repeatly read and print entries
  while ((de = readdir(dr)) != NULL)
    printf("%s\n", de->d_name);

  // Close directory
  closedir(dr);
  return 0;
}