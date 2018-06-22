#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char **argv)
{
  struct dirent *dir;
  DIR *d;
  char path[8192];
  struct stat buf;
  int noArgFlag;

  (argc < 2) ? (noArgFlag = 1) : (noArgFlag = 0);

  printf("\n");
  for (int i = 1; i < argc || noArgFlag; i++)
  {
    d = opendir(noArgFlag ? "." : argv[i]);
    if (d != NULL)
    {
      printf("Directory for \"%s\"\n", noArgFlag ? "." : argv[i]);
      while ((dir = readdir(d)) != NULL)
      {
        strcpy(path, noArgFlag ? "." : argv[i]);
        strcat(path, "/");
        strcat(path, dir->d_name);
        if (dir->d_type == 4)
          printf("%7s  %s\n", "<DIR>", dir->d_name);
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
      printf(" \"%s\"\n", noArgFlag ? "." : argv[i]);
      return 1;
    }
    noArgFlag = 0;
  }
  return 0;
}