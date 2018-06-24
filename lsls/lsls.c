#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

/*/  Helpers  /*/
size_t getFilesize(const char* filename) {
  struct stat st;
  if(stat(filename, &st) != 0) {
    return 0;
  }
  return st.st_size;   
}

// !!! SO CLOSE !!!
// Trying to aid in DRY by creating reusable function
// but it kept resulting in Segfault: 11 after printing
// all of the appropriate data
void printDir(char *filename) {
  DIR *dir;
  struct dirent *dp;

  dir = opendir(filename);

  while ((dp = readdir(dir)) != NULL) 
  {
    printf("%zu ", getFilesize(dp->d_name));
    printf ("%s\n", dp->d_name);
  }
}

/*/  Main  /*/
int main(int argc, char **argv)
{
  // Set up directory struct
  DIR *dir;
  struct dirent *dp;
  // No additional arguments
  if (argc == 1)
  {
    // Open current directory
    dir = opendir(".");
    // Print directory contents and file sizes
    while ((dp = readdir(dir)) != NULL) 
    { 
      printf("%zu ", getFilesize(dp->d_name));
      printf ("%s\n", dp->d_name);
    }
  }
  // Directory path is given
  else if (argc == 2)
  {
    // Open target directory
    dir = opendir(argv[1]);
    // Directory not found
    if (dir == NULL) 
    {
      perror("Cannot open");
      exit(1);
    }
    // Print directory contents and file sizes
    while ((dp = readdir(dir)) != NULL) 
    {
      // stat_filesize(dp->d_name);
      printf("%zu ", getFilesize(dp->d_name));
      printf ("%s\n", dp->d_name);
    }
  }
  // Too many arguments
  else 
  {
    perror("Too many arguments");
    exit(1);
  }
  // Close directory
  closedir(dir);

  return 0;
}