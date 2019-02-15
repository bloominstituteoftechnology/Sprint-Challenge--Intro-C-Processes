#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
//PR Text

int main(int argc, char **argv)
{
  // Parse command line

  DIR *dir;

  dir = argc < 1 ? opendir(".";) : opendir(*(argv+1));

  if(dir == NULL){
    printf("Nice try OMEGALUL")
  }





  // Open directory

  // Repeatly read and print entries

  // Close directory

  return 0;
}