#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // printf("code ran\n");
  // printf("0:%s\n",argv[0]);
  // printf("1:%s\n",argv[1]);
  // printf("2:%s\n",argv[2]);
  // printf("DONE");
  // Parse command line
  int length = argc;
  char* starting_dir;
  if(length >= 2){
    starting_dir = argv[1];
  }else{
    starting_dir = ".";
  }
  // Open directory
  DIR *dir;
  struct dirent *ent;
  ent = readdir(dir);
  if((dir = opendir(starting_dir)) != NULL){// Following code runs if current dir does not return Null
    while((ent = readdir(dir)) != NULL){
      // Repeatly read and print entries
      printf("Read Directory : %s\n", ent->d_name);
    }
  }else{
    printf("\nWARNING: Directory returned NULL please try again\n");
  }
  closedir(dir);
  return 0;
}

// 1. Call `opendir()`.
// 2. Then repeatedly call `readdir()`--printing the filenames as you go--until it
//    lets you know there are no more directory entries by returning `NULL`.
// 3. Then call `closedir()`.