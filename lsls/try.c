#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
  printf("===> try  ====================== \n");

  ///////////////////////////////////

  for (int i = 0; i < argc; i++)
  {

    printf(" arguments : %s \n", argv[i]);
  }

  //////////////////////////////////

  DIR *dir;
  struct dirent *sd;

  dir = opendir(".");

  if (dir == NULL)
  {
    printf("error unable to open dir \n");
    exit(1);
  }
  while ((sd = readdir(dir)) != NULL)
  {
    printf(" >> %s \n", sd->d_name);
  }
  closedir(dir);
  return (0);
}