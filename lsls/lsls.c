#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <string.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  struct dirent *Dirent;
  struct stat buf;
  DIR *dir;
  if (argc < 2)
  {
    dir = opendir(".");
  }
  else
  {
    dir = opendir(argv[1]);
  }

  if (dir == NULL)
  {
    printf("%d\n", errno);
    exit(1);
  }
  while ((Dirent = readdir(dir)) != NULL) 
  {
    if (argc < 2)
    {
      stat(Dirent->d_name, &buf);
      if (buf.st_mode == 16895) 
      {
        printf("%s %s\n", "<DIR>", Dirent->d_name);
      }
      else
      {
        printf("%ld %s\n", buf.st_size, Dirent->d_name);
      }
    }
    else
    {
      char *file_path = malloc(strlen(argv[1] + strlen(Dirent->d_name) + 2));
      sprintf(file_path, "%s/%s", argv[1], Dirent->d_name);
      stat(file_path, &buf);
      if (buf.st_mode == 16895) 
      {
        printf("%s %s\n", "<DIR>", Dirent->d_name);
      }
      else
      {
        printf("%ld %s\n", buf.st_size, Dirent->d_name);
      }
      free(file_path);
    }
  }
  closedir(dir);
  return 0;
}