#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  **argv = calloc (argc,sizeof(char*));
  DIR *d;
  struct dirent *ent;
  
  d = opendir(argv[argc-1]);
  if (d == NULL) {
    exit(1);
  }
  ent = readdir(d);
  while ((ent = readdir(d)) != NULL) {
    printf ("%s\n", ent->d_name);
  }
    

  closedir(d);
  return 0; 
  
}