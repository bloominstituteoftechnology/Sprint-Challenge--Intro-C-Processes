#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  struct dirent *de;
  struct stat buf;
  DIR *d;
  char *dir_name;

 if (argc < 2)
  {
    
    dir_name = ".";
  }
  else if (argc == 2)
  {
    dir_name = argv[1];
  }
  else
  {
    printf("Cannot open directory '%s'", argv[1]);
    return 1;
  }

  // Open directory
  d = opendir(dir_name);



  // Repeatly read and print entries, calling readdir until it is NULL
  while ((de = readdir(d)) != NULL)
  {
    char buffer[256];
    snprintf(buffer, sizeof buffer, "%s%s%s", dir_name, "/", de->d_name);
    stat(buffer, &buf);
    printf("%10ld %s\n", buf.st_size, de->d_name);
    //make char *fullpath and mallloc bytes
    // char *fullpath = malloc(byte_size);

    //combine the fullpath and d_name
    // sprintf(fullpath, "%s%s", d, de->d_name);

    //use stat call in sys.stat.h on fullpath and struct stat buf, check if -1
    // if(stat(fullpath, &buf) == -1){
    //   perror("stat was -1");
    //   continue;
    // };
    //use %10lld to print width of 10
    // printf("%10lld %s\n", buf.st_size, de->d_name);
  }

  // Close directory
  closedir(d);
  return 0;
}