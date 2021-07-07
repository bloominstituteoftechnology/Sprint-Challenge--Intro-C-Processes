#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  struct dirent *d;
  DIR *directory;
  // Open directory
  if (argc > 2) {
    directory = opendir(argv[1]);
  }
    else{
    directory = opendir(".");
    } 
  if (directory == NULL) {
    printf("error\n");
    exit(1);
  }
  while((d = readdir(directory))!= NULL)
    printf("%s\n", d->d_name);
  // Close directory
  closedir(directory);


  return 0;
}