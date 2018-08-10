#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>



void concatenate(char p[], char q[]) {
   int c, d;
 
   c = 0;
 
   while (p[c] != '\0') {
      c++;      
   }
 
   d = 0;
 
   while (q[d] != '\0') {
      p[c] = q[d];
      d++;
      c++;    
   }
 
   p[c] = '\0';
}
/**
 * Main
 */
int main(int argc, char **argv)
{
  char* path;
  if(argc == 1){
    path =  ".";
  }
  else{
    path =  argv[1];
  }
  // Parse command line
  
  // DIR *opendir(char *path);


  struct dirent *ent;
  struct stat buf; // Pointer for directory entry
 
    // opendir() returns a pointer of DIR type. 
    DIR *dr = opendir(path);
 
    if (dr == NULL)  
    {
        printf("Could not open current directory" );
        return 0;
    }

    char path2[] = "./Users/samar/code/c/Sprint-Challenge--Intro-C-Processes/lsls/";
    char* path3;
    // strcat(path2, path3);
    // printf("%s",path2);


    while ((ent = readdir(dr)) != NULL){
      //concatenate(path2, ent->d_name);
      //printf("%s", path2);
      // strcat(path2, path);
      //stat(path2, &buf);
      // printf("%s",path2);

      //printf("%s and file size is %10lld\n", ent->d_name, buf.st_size);
      printf("%s \n", ent->d_name);
    }
      
 
    closedir(dr);    
    return 0;

  

  // stat("./lsls.c", &buf);

  // printf("file size is %lld\n", buf.st_size);
  // Open directory

  // Repeatly read and print entries

  // Close directory
}