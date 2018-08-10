#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *d;
  struct dirent *dir;
  struct stat buf;

  d = (argc > 1) ? opendir(argv[1]) : opendir(".");

  if(d == NULL)
  {
    fprintf(stderr, "Error opening directory");
    return 0;
  }

    while ((dir = readdir(d)) != NULL) { 
    {
      stat(dir->d_name, & buf);
      if(buf.st_mode & __S_IFDIR)
      {
        printf("%10s --- %s\n", "<DIR>", dir->d_name);
      }
      else
      {
        printf("%10llu --- %s\n", buf.st_size, dir->d_name);
      }
    }
  closedir(d);
  return(0);
}