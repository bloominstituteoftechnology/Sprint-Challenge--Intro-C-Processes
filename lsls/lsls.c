#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

void errorOut(int code)
{
  exit(code);
}

void handleReadDir(char *toOpen)
{
  // Parse command line
  struct dirent *de;

  // Open directory
  DIR *dr = opendir(toOpen);
  // Repeatly read and print entries
  if (dr == NULL)
  {
    printf("Unable to open directory");
    errorOut(0);
  }

  while ((de = readdir(dr)) != NULL)
  {
    printf("%s\n", de->d_name);
  }
  // Close directory
  closedir(dr);
}

/**
 * Main
 */
int main(int argc, char **argv)
{

  if (argc >= 2)
  {
    handleReadDir(argv[1]);
  }
  else
  {
    handleReadDir(".");
  }

  return 0;
}
