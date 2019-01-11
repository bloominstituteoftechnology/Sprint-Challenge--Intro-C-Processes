#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char *directory = (char *) malloc(64);
  if(argc > 2)
  {
    printf("More than 2 arguments detected. Will ignore excess.");
  }
  else if(argc == 2)
  {
    char *p = argv[1];
    int i;
    for(i=0; p[i]!='\0'; i++)
    {
      directory[i] = p[i];
    }
    directory[i] = '\0';
  }
  else
  {
    directory[0] = '.';
    directory[1] = '\0';
  }
  // Open directory
  DIR *dir = malloc(sizeof(DIR));
  dir = opendir(directory);
  if(dir == NULL)
  {
    fprintf(stderr, "opendir() returned NULL");
    exit(2);
  }
  // Repeatly read and print entries
  struct dirent *dp = readdir(dir);
  while(dp!=NULL){
    printf("%s\n", dp->d_name);
    dp = readdir(dir);
  }
  
  // Close directory

  return 0;
}