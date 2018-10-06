#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>

    /**
 * Main
 */
int main(int argc, char *argv)
{
  DIR *d;
  struct dirent *dir;
  struct stat buf;
  printf("Enter a directory: \n");
  scanf("%s", argv);
  d = opendir(argv);

  if( !d ) {
    d = opendir(".");
  }

  if (d == NULL) {
    printf("There was an error opening this directory");
    exit(0);
  }

  while ((dir = readdir(d)) != NULL)
  {
    stat(dir->d_name, &buf);
    printf("%10ld  ", buf.st_size);
    printf("%s\n", dir->d_name);
  }
  closedir(d);

  return 0;

  }
