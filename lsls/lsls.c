#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char **argv)
{
  struct dirent *dir;
  DIR *d;
  char path[50];
  struct stat buf;

  printf("\n");

  for (int i = 1; i < argc; i++)
  {
    d = opendir(argv[i]);
    if (d != NULL)
    {
      printf("Directory for \"%s\"\n", argv[i]);
      while ((dir = readdir(d)) != NULL)
      {
        strcpy(path, argv[i]);
        strcat(path, "/");
        strcat(path, dir->d_name);
        if (dir->d_type == 4)
        {
          printf("  <DIR>  %s\n", dir->d_name);
        }
        else
        {
          stat(path, &buf);
          printf("%7ld  %s\n", buf.st_size, dir->d_name);
        }
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