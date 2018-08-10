#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char *dirname;
  // if no additional arguments added, just print current dir
  if (argc == 1)
  {
    dirname = ".";
  }
  // if there is an argument, print that directory
  else if (argc == 2)
  {
    dirname = argv[1];
  }
  // otherwise, error - try again
  else
  {
    fprintf(stderr, "Try again - usage: './lsls (dirname)\n");
    exit(1);
  }
  // Open directory
  struct dirent *dir;
  DIR *d = opendir(dirname);
  // Repeatly read and print entries
  if (d)
  {
    while ((dir = readdir(d)) != NULL)
    {
      struct stat st;

      if (stat(dir->d_name, &st) < 0)
      {
        fprintf(stderr, "oops, can't stat file\n");
        exit(2);
      }
      if (st.st_mode & S_IFREG) 
      {
        printf("%s %jd\n", dir->d_name,st.st_size);
      }
      else
      {
        printf("%s\n", dir->d_name);
      }
    }
  // Close directory
    closedir(d);
  }
  return 0;
}
