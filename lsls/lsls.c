#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  if (argc < 2)
  {
    fprintf(stderr, "usage: lsls <dirname>\n");
    exit(1);
  }

  char *dirname = argv[1];

  // Open directory
  DIR *dir;
  if((dir = opendir(dirname)) == NULL)
  {
    char error_msg[] = "Cannot open directory ";
    strcat(error_msg, dirname);
    perror(error_msg);
    exit(1);
  }

  // Repeatly read and print entries

  // Close directory
  closedir(dir);

  return 0;
}