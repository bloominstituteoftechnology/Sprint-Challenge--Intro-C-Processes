#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  DIR *dir;

  dir = opendir(".");
  if(dir == NULL) {
    printf("stdError cannot open directory \n");
    exit(1);
  }
  struct dirent *ent;
  while((ent=readdir(dir)) != NULL) {
      printf("%s\n", ent->d_name);
  }

  closedir(dir);

  return 0;
}

