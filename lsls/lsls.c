#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char *dir; //

  if(argc == 1) { // argc is the number of arguments being passed 
                  // argv is the arguments being passed.
    dir = ".";
  } else if ( argc == 2) {
    dir = argv[1];
  } else {
    printf("error to many directories [dir] \n  ");
    return 1;
  }

  DIR *d =opendir(dir);

  if(d == NULL) {
    printf("stdError cannot open directory \n");
    exit(1);
  }
  struct dirent *ent;
  while((ent=readdir(d)) != NULL) {
      printf("%s\n", ent->d_name);
  }

  closedir(d);

  return 0;
}

