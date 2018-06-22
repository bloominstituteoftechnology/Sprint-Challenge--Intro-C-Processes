#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  DIR *dir;
  char *d_arg;
  struct dirent *sd;
  // Open directory
  if(argc == 1){
      d_arg = ".";
  }else if(argc == 2 ){
      d_arg = argv[1];
  }else{
    fprintf(stderr, "an error occured\n" );
    exit(1);
  }
  dir =opendir(d_arg);
  // Repeatly read and print entries

  while( (sd=readdir(dir)) !=NULL ){
    printf(">> %s\n", sd->d_name);
  }
  // Close directory
  closedir(dir);

  return 0;
}
