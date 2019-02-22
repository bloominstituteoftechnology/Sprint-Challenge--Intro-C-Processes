#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *dir;
  
  if (argc < 2) 
  {
    dir = opendir(".");
  }else {
    dir=opendir(argv[1]);
  }

  if (dir == NULL){
    printf(">> There was an error attempting to read the directory. Check the path.\n");
    exit(EXIT_FAILURE);
  }
  
  struct dirent* directory_entry;
  struct stat buf;

  while(1){
    directory_entry = readdir(dir);
    if (directory_entry == NULL){
      break;
    }
    stat(directory_entry->d_name, &buf);
    printf("%lld\t%s\n", buf.st_size, directory_entry->d_name);

  }

  // Close directory
  closedir(dir);

  return 0;
}