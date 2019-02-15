#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h> // To get the size of entries, you'll need to use the `stat()` call in `<sys/stat.h>`.
/**
 * Main
 * 
 *TO_DO = figure out if code isn't working or test ----------
*/
int main(int argc, char **argv)
{
  //declarations
  
  struct dirent *dir;
 // struct stat buf; 
  char *directory;
  

  // Parse command line/
  
  if (argc == 1) {
     //if 1, use current directory
    directory = ".";
    printf("Directory: %s\n", directory);

  } else if(argc == 2) {
    //if two, use the second(index 1) as the name of the directory 
    directory = argv[1];
    printf("Directory: %s\n", directory);

  } else {
    fprintf(stderr, "usage: lsls [dirname]\n");
    exit(1);
  }
  
  
  // Open directory 
  DIR *d = opendir(directory);
  if (d == NULL)
  {
    fprintf(stderr, "Cannot find directory\n");
    exit(2);
  }

  // Repeatedly read and print entries 
  while ((dir = readdir(d)) != NULL) {
    char fullpath[4096];
    struct stat stat_buf;

    snprintf(fullpath,sizeof(fullpath), "%s/%s", directory,dir->d_name);// d_name = file name, a string
    printf("%s\n",dir->d_name);

   if(stat(fullpath, &stat_buf)< 0){
     fprintf(stderr, "failed to stat file %s\n", fullpath);
     exit(3);
   }; 
   
    
    //print file name and file size req 
    printf("%s\n", dir->d_name);
    printf("file size is %lld %s\n ", stat_buf.st_size,dir->d_name); 

    }

  // Close directory 
    closedir(d);
  
  return 0;
}