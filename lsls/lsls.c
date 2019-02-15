#include <stdio.h>
#include <dirent.h>
#include <string.h>
# include <sys/stat.h>
# include <stdlib.h>
/**
 * Main
 */
//PR Text

int main(int argc, char **argv)
{
  // Parse command line

  DIR *dir;
 
  
  struct dirent *sd;

  dir = (argc < 2) ? opendir(".") : opendir(*(argv+1));

  if(dir == NULL){
    printf("Nice try OMEGALUL");
  }

  while( (sd=readdir(dir)) != NULL){
    struct stat buf;
    
    stat((argv[1],sd->d_name), &buf);
    printf("%ld", buf.st_size);
    printf("              ");
    printf("%s\n", sd->d_name);
  }




  closedir(dir);
  // Open directory

  // Repeatly read and print entries

  // Close directory

  return 0;
}