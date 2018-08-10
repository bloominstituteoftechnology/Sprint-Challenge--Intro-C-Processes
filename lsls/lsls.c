#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>


int main(int argc, char **argv)
{
  DIR *dir;
  struct dirent *sd;
  int i;

  struct stat buf;
  // Parse command line

  // Open directory
  if (argc<=1)
    {
        dir = opendir(".");
    }
    else
    {
        dir = opendir(argv[1]);
    }
  // Repeatly read and print entries
  if (dir==NULL)
    {
        printf("Error . is NULL, unable to open.\n");
        exit(1);
    }

printf("this is the dir %s\n", argv[1]);
    while((sd=readdir(dir)) != NULL)
    {
      char file_path[80];
      strcpy(file_path, argv[1]);
      strcat(file_path, sd->d_name);

      if (stat(file_path, &buf) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
      }

      if((buf.st_mode & S_IFDIR) != 0){
        printf("<DIR>\n");
        printf("Directory Name: %s\n", sd->d_name);
      }
      else{
      
      
      printf("File Size: \t\t%d bytes\n",buf.st_size);
      printf("File Name: %s\n", sd->d_name);
      }
    }

  // Close directory
  closedir(dir);
  return 0;
}