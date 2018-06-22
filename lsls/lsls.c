#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  char *directoryPath;
  // Parse command line
if(argc == 1)
{
  directoryPath=".";
}
else if(argc == 2);
{
directoryPath = argv[1];
}
  // Open directory
  struct dirent *entry;
DIR *openedDirecectory =opendir(directoryPath);
  // Repeatly read and print entries
  if (openedDirecectory ==NULL)
  {
    fprintf(stderr,"cannot open directory");
    exit(1);
  }
  while((entry = readdir(openedDirecectory)) !=NULL)
  {
    printf("Entry: %s\n", entry->d_name);
  }

  // Close directory
closedir(openedDirecectory);
  return 0;
}