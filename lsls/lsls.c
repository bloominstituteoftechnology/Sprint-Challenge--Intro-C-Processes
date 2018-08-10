#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>


/**
 * Main
 */
int main(int argc, char **argv)
{
  // Open directory & Setup
  // create "object" to save file structure
  struct dirent *parent_dir;
  char path;

  // create pointer for the directory
  DIR *dir;

  // open directory with appropriat path
  if(argc < 2){
    dir = opendir(".");
  }else{
    dir = opendir(argv[1]);
  }

  // function that executes stat, gets passed the file_path
  // returns unsigned integer(?)
  // takes the stat struct out of global namespace
  size_t getFilesize(const char* file_path) {
    struct stat buf;
    if(stat(file_path, &buf) !=0){
      return 0;
    }
    return buf.st_size;
  }

  int isDir(const char* file_path){
    struct stat dir;
    stat(file_path, &dir);
    return S_ISREG(dir.st_mode);
  }


  // helper function to concat the three variables to 
  // a valid filepath
  char *concatenate(char *a, char *b, char *c)
{
  int size = strlen(a) + strlen(b) + strlen(c) + 1;
  char *str = malloc(size);
  strcpy (str, a);
  strcat (str, b);
  strcat (str, c); 

  return str;
}

  // Repeatly read and print entries
  // sets key - values pairs in our dir-struct and then prints them
    while((parent_dir = readdir(dir))!= NULL){

      if(argc < 2){
        if(!isDir(concatenate(".", "/", parent_dir->d_name))){
          printf("<DIR>    ");
        }else
          printf("%zu    ",getFilesize(concatenate(".", "/", parent_dir->d_name)));
    }else{
        if(!isDir(concatenate(".", "/", parent_dir->d_name))){
          printf("<DIR>    ");
        }else{
          printf("%zu    ", getFilesize(concatenate(argv[1], "/", parent_dir->d_name)));
        } 
      }
      printf("%s\n", parent_dir->d_name);
    }

  // Close directory
  closedir(dir);
  return 0;
}
