#include <stdio.h>
#include <dirent.h>

int main(int argc, char **argv){
  // create pointers
  DIR *directory;
  struct dirent *d_ent;

  // open directory
  if (argc > 1){
    directory = opendir(argv[1]);
  } else{
  directory = opendir(".");
  }
 
  if (directory == NULL){
    fprintf(stderr, "Directory not present.");
    return 0;
  }

  // read and print entries
  while ((d_ent = readdir(directory)) != NULL){
    printf("%s", d_ent->d_name);
  }

  // close directory
  closedir(directory);

  return 0;
}