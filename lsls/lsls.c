#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>


/**
 * Main
 */

int directoryList(const char *path)
{
  struct dirent *entry;
  DIR *dir;

  //open directory stream
  dir = opendir(path);
  if (dir == NULL)
  {
    fprintf(stderr, "err opendir - double check path name %s\n", path);
    exit(2); //inability to compare - error thrown and exit process
  }

  while((entry = readdir(dir))){
    puts(entry->d_name);
  }
  //close stream
  closedir(dir);
  return 0;
}

int main(int argc, char **argv)
{
  struct stat file_stat;

  int counter = 1;

  //current working directory if no arguments on command line

  if (argc == 1)
  {
    directoryList(".");
  }
  //dir in command line 
  //tested with ../../Github

  while(counter < argc){
    if (lstat(argv[counter], &file_stat) == -1){
      fprintf(stderr, "%s\n", strerror(errno));
    }
    else {
      fprintf(stdout, "\nDirectory Listing %s %lldbytes\n", argv[counter], file_stat.st_size);
      directoryList(argv[counter]);
      counter++;
    }
  }
  return 0;
}