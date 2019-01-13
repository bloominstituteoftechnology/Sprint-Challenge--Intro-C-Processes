#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char *directory = (char *) malloc(64);
  if(argc > 2)
  {
    printf("More than 2 arguments detected. Will ignore excess.");
  }
  else if(argc == 2)
  {
    char *p = argv[1];
    int i;
    for(i=0; p[i]!='\0'; i++)
    {
      directory[i] = p[i];
    }
    directory[i] = '\0';
  }
  else
  {
    directory[0] = '.';
    directory[1] = '\0';
  }
  // Open directory
  DIR *dir = malloc(sizeof(DIR));
  dir = opendir(directory);
  if(dir == NULL)
  {
    fprintf(stderr, "opendir() returned NULL");
    exit(2);
  }
  // Repeatly read and print entries
  struct dirent *dp = readdir(dir);
  struct stat buf;
  while(dp!=NULL){
    stat(dp->d_name, &buf);
    // int ifmt = buf.st_mode & S_IFMT;
    if((buf.st_mode & S_IFMT) == S_IFDIR)
    {
      printf("IFDIR result: %d\n", buf.st_mode&S_IFDIR);
    }
    else if((buf.st_mode & S_IFMT) == S_IFREG)
    {
      printf("IFREG result: %d\n", buf.st_mode&S_IFREG);
    }
    else
    {
      printf("Ya done messed up boy.\n");
    }
    printf("%10lld %s\n", buf.st_size, dp->d_name);
    dp = readdir(dir);
  }
  // Close directory
  closedir(dir);
  return 0;
}