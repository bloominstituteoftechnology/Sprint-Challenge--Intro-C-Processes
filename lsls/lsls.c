#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *dir;
  struct dirent *pDirent;
  struct stat buf;

  // Parse command line
  if (argc < 2) // Default current dir
  {
    dir = opendir(".");
    argv[1] = ".";
  }
  else
  {
    dir = opendir(argv[1]); // dir path
  }
  // Open directory
  if (dir == NULL)
  {
    printf("The directory is empty! :(\n"); // test ./lsls x
    exit(1);
  }
  // Repeatly read and print entries
  else
  {
    while ((pDirent = readdir(dir)) != NULL) // read while dir not empty
    {
      stat((*pDirent).d_name, &buf);
      printf("%s\t %ld\n", (*pDirent).d_name, buf.st_size);
    }
  }

  // Close directory
  closedir(dir);

  return 0;
}