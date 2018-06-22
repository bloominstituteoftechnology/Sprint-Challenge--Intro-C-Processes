#include <stdio.h>
#include <dirent.h>

int main(int argc, char **argv)
{
  struct dirent *dir;
  DIR *d;

  for (int i = 1; i < argc; i++)
  {
    d = opendir(argv[i]);
    if (d != NULL)
    {
      dir = readdir(d);

      while ((dir = readdir(d)) != NULL)
      {
        printf("%s\n", dir->d_name);
      }

      closedir(d);
      printf("\n");
    }
    else
    {
      perror("");
      return 1;
    }
  }
  return 0;
}