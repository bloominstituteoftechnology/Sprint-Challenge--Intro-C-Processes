#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  struct dirent *de;
  struct stat buf;
  char *path;
  char full_path[100];
  char src[100];
  strcpy(full_path, "./");
  // strcat(full_path, src);

  // Parse command line
  if (argv[1] != NULL)
  {
    path = argv[1];
    strcat(full_path, path);
  }
  else
  {
    path = ".";
  }

  // Open directory
  DIR *d = opendir(path);

  // Check for errors
  if (d == NULL)
  {
    printf("The directory does not exist.\n");
    exit(0);
  }

  printf("Testing path: %s\n", path);

  printf("beginning: %s\n", full_path);
  // Repeatly read and print entries
  while ((de = readdir(d)) != NULL)
  {

    // ./ + path + de->d_name

    // strcat(full_path, de->d_name);
    printf("%s\n", full_path);
    // if (stat(full_path, &buf) != -1)
    {
      printf("%10lld %s\n", buf.st_size, de->d_name);
      // }
      // else
      // {
      //   printf("There was an error accessing the file size.\n");
      //   exit(1);
      // }
    }

    // Close directory
    closedir(d);

    return 0;
  }