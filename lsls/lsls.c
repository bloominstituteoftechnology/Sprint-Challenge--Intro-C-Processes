#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

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
   printf("Cannot open directory %s\n", dir_name);
   return 1;

}else{
  
  // Repeatly read and print entries
    struct stat buf;
    char fullpath[9000];
while((p_dirent = readdir(p_dir)) != NULL){
    sprintf(fullpath, "%s/%s", dir_name, p_dirent->d_name);
    stat(fullpath, &buf);
    printf("FILE SIZE:%ld %s\n", buf.st_size, p_dirent->d_name);
  } 
 }
  // Close directory
  closedir(p_dir);
  return 0;
}
