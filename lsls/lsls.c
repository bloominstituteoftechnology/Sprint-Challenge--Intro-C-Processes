#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/types.h>

/**
 * Main
 */

// SO... What's all this about?
// argv[0] == ./lsls
// argv[1] == null
// argv[2] == TERM_PROGRAM=Apple_Terminal
// argv[3] == SHELL=/bin/bash
// argv[4] == TERM=xterm-256color

int main(int argc, char **argv)
{
  // Parse command line
 char *dirname;

  // 0 argc isn't possible -.-
  // if(argc == 0) 
  // {
  //   dirname = ".";
  // }
  
  if(argc == 1)
  {
    dirname = ".";
    printf("At argv[0] the dirname = %s\n", dirname);
  }
  else if(argc == 2)
  {
    dirname = argv[1];
    printf("At argv[1] the dirname = %s\n", dirname);
  }
  else 
  {
    fprintf(stderr, "Error working with %s\n", dirname);
  }

    // VERY HELPFUL FOR TESTING
    // int i;

    // printf("There are %d command line argument(s):\n", argc);

    // for (i = 0; i < argc; i++) {
    //     printf("   %s\n", argv[i]);
    // }

  // Open directory
  DIR *dir;
  dir = opendir(dirname);
  struct dirent *dp;

  if(dir == NULL)
  {
    fprintf(stderr, "ERROR Failed to open dir %s\n", dirname);
    exit(1);
  }

  // Repeatly read and print entries
  while((dp = readdir(dir)) != NULL) 
  {
    printf(">> %s\n", dp->d_name);
  }

  // Close directory
  closedir(dir);

  return 0;
}