#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Open directory & Setup
  // create "object" to save file structure
  struct dirent *parent_dir;
  DIR *dir;

  if(argc < 2)
  {
    dir = opendir(".");
  }
  else
  {
    dir = opendir(argv[1]);
  }

  if (dir == NULL) {
    fprintf(stderr, "Error opening directory\n");
    return 0;
  }

  while((parent_dir = readdir(dir))!= NULL)
  {
    if(argc < 2)
    {
      printf("./%s\n", parent_dir->d_name);
    }
    else
    {
      printf("%s\n", parent_dir->d_name);
    }
  }

  // Close directory
  closedir(dir);
  return 0;
}