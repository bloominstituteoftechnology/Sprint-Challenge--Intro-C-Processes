#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc)//, char *argv)
{
  //variables
  DIR *dir;
  char *str[80];
  struct dirent *ent;
  // Parse command line
  
  // Open directory
  dir = opendir(".");

  ent = readdir(dir);

  if (!ent) {
    printf("Nothing in this directory ¯\_(ツ)_/¯");
  }
  else {
    while(ent){
      printf("%s\n",ent->d_name);
    }
  }
  

  

  closedir(dir);



  // Repeatly read and print entries

  // Close directory

  return 0;
}