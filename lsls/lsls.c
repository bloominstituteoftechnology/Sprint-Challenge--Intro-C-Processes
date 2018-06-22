#include <stdio.h>
#include <dirent.h>

int main(int argc, char **argv)
{
  struct dirent *dir;
  DIR *d;
  // char path[50];

  printf("\n");

  for (int i = 1; i < argc; i++)
  {
    d = opendir(argv[i]);
    // strcpy(path, argv[i]);
    if (d != NULL)
    {
      printf("Directory for \"%s\"\n", argv[i]);
      while ((dir = readdir(d)) != NULL)
      {
        if (dir->d_type == 4)
        {
          printf("<DIR>  %s\n", dir->d_name);
        }
        else
          printf("       %s\n", dir->d_name);
      }

      closedir(d);
      printf("\n");
    }
    else
    {
      perror("");
      printf(" \"%s\"\n", argv[i]);
      return 1;
    }
  }
  return 0;
}