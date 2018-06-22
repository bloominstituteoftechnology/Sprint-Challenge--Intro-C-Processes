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
  if (argc == 1)
    argv[0] = ".";
  d = opendir(argv[0]);
  if (d != NULL)
  {
    printf("Directory for \"%s\"\n", argv[0]);
    while ((dir = readdir(d)) != NULL)
    {
      strcpy(path, argv[0]);
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
    printf("\n");
  }
  else
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