#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
// #include <unistd.h>
// #include <stdio.h>
// #include <limits.h>

#define SOME_SIZE 2046
/**
 * Main
 */
int main(int argc, char **argv)
{
  // to see argv
  // printf("There are %d command line argument(s):\n", argc);
  // for (int i = 0; i < argc; i++)
  // {
  //   printf("   %s\n", argv[i]);
  // }
  
  DIR *pDir;
  struct dirent *pDirent;
  struct stat buf;

  // Parse command line
  // from the **argv

  // Open directory
  if (argc < 2)
  {
    // if directory is not specified/current directory path: "./"
    pDir = opendir("./");
  }
  else
  {
    // if directory is specified.
    pDir = opendir(argv[1]);
  }
  // check directory to see if it is NULL
  if (pDir == NULL)
  {
    printf("Cannot open directory '%s'\n", argv[1]);
    return 1;
  }

  // Repeatly read and print entries
  while ((pDirent = readdir(pDir)) != NULL)
  {
    // char *a = "";
    // char *b = pDirent->d_name;
    // char buf2[SOME_SIZE];

    // strcat(buf2, a);
    // strcat(buf2, b);
    // stat(buf2, &buf);
    stat(pDirent->d_name, &buf);
    printf("%ld %s\n", buf.st_size, pDirent->d_name);
    // printf("%s\n",pDirent->d_name);
  }

  // Close directory
  closedir(pDir);

  return 0;
}