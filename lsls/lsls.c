#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  int i;
  printf("There are %d command line argument(s):\n", argc);
  for (i = 0; i < argc; i++)
  {
    printf("   %s\n", argv[i]);
  }

  char *dir_path;
  if (argv[1] != NULL)
  {

    dir_path = argv[1];
    printf("arg 2%s \n", argv[1]);
  }
  else
  {
    dir_path = argv[0];
  }

  // Open directory
  DIR *dir;
  struct dirent *sd;
 
  if ((dir =opendir(dir_path)) == NULL)
  {
    printf("error, can not open that directory \n");
    exit(1);
  }
  struct stat buf;
  while ((sd = readdir(dir)) != NULL)
  {
    char file_name[100] = "";

    strcat(file_name, dir_path);
    strcat(file_name, "/");
    strcat(file_name, sd->d_name);
    stat(file_name, &buf);
    printf(">>     %s   File size is %10ld\n", sd->d_name, buf.st_size);
  }
  closedir(dir);
  return 0;
}
