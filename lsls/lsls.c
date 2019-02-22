#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *dir;
  // Parse command line
  if (argc < 2) 
  {
    dir = opendir(".");
  }else {
    dir=opendir(argv[1]);
  }
  // Open directory
  struct dirent* directory_entry;
  struct stat buf;

  while(1){
    directory_entry = readdir(dir);
    if (directory_entry == NULL){
      break;
    }
    printf("%s\n", directory_entry->d_name);
  }
  

  // Repeatly read and print entries

  // Close directory

  return 0;
}