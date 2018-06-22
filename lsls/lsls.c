#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  int i;
  struct dirent *dp;
  char *path;

  printf("There are %d command line argument(s):\n", argc);

  for (i = 0; i < argc; i++) {
      printf("   %s\n", argv[i]);
  }

  if(argv[1]){
    path = argv[1];
  } else path = ".";

  DIR *d = opendir(path);

  if(d == NULL){
    fprintf(stderr, "Invalid path specified");
    return 1;
  }

  // put two readdirs first if you want to get rid of the . and .. default paths displaying every time you run this
  dp = readdir(d);
  dp = readdir(d);

  while((dp = readdir(d)) != NULL){
    printf("Filename: %s\n", dp->d_name);
  }
  
  closedir(d);
  return 0;
}