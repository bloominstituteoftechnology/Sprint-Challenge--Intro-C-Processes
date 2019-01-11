#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv){
  char *dir_name;
  struct dirent *p_dirent;
  DIR *p_dir;
  
  // Parse command line
   if(argc == 1){
      dir_name = "."; 
    printf("Directory: %s", dir_name);
  }else if(argc ==2){
    dir_name = argv[1];
  }else{
    printf("Directory could not be opened");
    return 1;
  }
  
  // Open directory
 p_dir = opendir(dir_name);
 if(p_dir == NULL){
   printf("Cannot open directory %s\n", argv[1]);
   return 1;
 
}else{
  
  // Repeatly read and print entries
while((p_dirent = readdir(p_dir)) != NULL){
    printf("%s\n", p_dirent->d_name);
  }
 }

  // Close directory
  closedir(p_dir);
  return 0;
}