#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
/**
 * Main
 */
int main(int argc, char **argv)
{
  char *directory;
  DIR *dir;
  struct dirent *dp;
  // Parse command line
  printf("argc : %d\n", argc);
  int index = 0;
  for (index = 0; index < argc; index++) {
    if (argc < 2) {
      directory = ".";
      printf("directory: %s\n", directory);
    } else if (argc == 2){
        directory = argv[1];
        printf("directory: %s\n", directory);
    }  
    printf("argv[%d] : %s\n",index, argv[index]);
  }

  // Open directory
  dir = opendir(directory);
  // Repeatly read and print entries
  while ((dp = readdir(dir)) != NULL) {
    char *name = dp->d_name;
    struct stat buf;
    stat(name, &buf);
    printf("%10lld %s\n",buf.st_size, name);
  }
  // Close directory
  closedir(dir);
  return 0;
}