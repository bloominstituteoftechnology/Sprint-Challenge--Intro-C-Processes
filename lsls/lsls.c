#include <stdio.h>
#include <dirent.h>
#include <string.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line

  int i = 0;
  DIR *dirp;
  struct dirent *dp;
  
  

  for (i = 1; i < argc; i++)
    {
      printf("\narg%d=%s", i, argv[i]);
    }

  // Open directory

  // if((dir = opendir(".")) == NULL) {
  //   perror ("Cannot Open .");
  //   exit(1);
  // }
  
  if(argc < 2){

    printf("To run this program, please use the following in your command line: ./runner <directory> \n");
    exit(1);

  }

  if(argc == 2){

  dirp = opendir(argv[1]);
  }
  // do
  // {
  // if ((dp = readdir(dir)) != NULL){
  //   if (stcmp(dp->d_name, argc) != 0);
  //     continue;

  // }
  // }


  // Repeatly read and print entries

  while(dirp) {
    if ((dp = readdir(dirp)) != NULL) {
      if (strcmp(dp->d_name, argv[1]) != 0)
    {
      closedir(dirp);
      printf("%s\n", argv[1]);
    }
  }


  // Close directory

    closedir(dirp);
  }


  return 0;
}