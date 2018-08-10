#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  //variables
  DIR *dir;
  char *str[80];
  struct dirent *ent;
  
  // Open directory
  dir = opendir(argv[1]);
  ent = readdir(dir);
  if (!ent) {
    printf("Nothing in this directory ¯\(ツ)/¯");
  }
  else {
    while((ent = readdir(dir)) != NULL){

      printf("%s\n",ent->d_name);   
    }
  }
  closedir(dir);
  return 0;
}