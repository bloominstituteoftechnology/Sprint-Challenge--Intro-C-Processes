#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  // // printf("Enter a command: ");
  // char command[256];
  // fgets(command, sizeof(command), stdin);

  // char *nl = strrchr(command, '\n');
  // if (nl != NULL){
  //   *nl = '\0';
  char *dir_str;
  if (argc == 1){
    dir_str = ".";
  }
  else {
    dir_str = argv[1];
  }
  printf("directory is : %s\n", dir_str);
  // for (int i = 0; i < argc; i++) {
  //     printf("   %s\n", argv[i]);
  // }
 

  // Open directory
  DIR *dir = opendir(dir_str);

  if (dir == NULL){
    printf("directory not found");
    exit(0);
  }
  // Repeatly read and print entries
  else{
    struct dirent *dp;
    while( (dp  = readdir(dir))  != NULL){
      if ( dp != NULL) {
        struct stat statbuf;
        stat(dp->d_name, &statbuf);
        printf("%10ld %s\n", statbuf.st_size, dp->d_name);
      }
      else{
        exit(0);
      }
    }
  }

  // Close directory
  closedir(dir);

  return 0;
}