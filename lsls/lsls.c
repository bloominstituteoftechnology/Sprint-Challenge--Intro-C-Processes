#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *d;
  struct dirent *dir;
  printf("Enter a directory: \n");
  scanf("%c", argv);
  if(argv < 1) {
    d = opendir(".");
  }
  else {
    d = opendir(argv);
  }
  if (d)
  {
    while ((dir = readdir(d)) != NULL)
    {
      printf("%s\n", dir->d_name);
    }
    closedir(d);
  }
  return 0;

  }
