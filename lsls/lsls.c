#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
// #include <unistd.h>
// #include <stdio.h>
// #include <limits.h>

// #define SOME_SIZE 2046
/**
 * Main
 */

int print_second_directory(char *pDirent)
{
  DIR *pDir2;
  struct dirent *pDirent2;
  struct stat buf3;
  pDir2 = opendir(pDirent);
  if (pDir2 == NULL)
  {
    printf("Cannot open directory '%s'\n", pDirent);
    return 1;
  }
  while ((pDirent2 = readdir(pDir2)) != NULL)
  {
    stat(pDirent2->d_name, &buf3);
    if (S_ISDIR(buf3.st_mode) == 1)
    {
      printf("    <DIR> %s\n", pDirent2->d_name);
    }
    else if (S_ISREG(buf3.st_mode) == 1)
    {
      printf("    %ld %s\n", buf3.st_size, pDirent2->d_name);
    }
  }
  closedir(pDir2);

  return 0;
}

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
    // printf("dir: %d\n",S_ISDIR(buf.st_mode));
    // printf("file: %d\n",S_ISREG(buf.st_mode));
    if (S_ISDIR(buf.st_mode) == 1)
    {
      printf("<DIR> %s\n", pDirent->d_name);
      print_second_directory(pDirent->d_name);
    }
    else if (S_ISREG(buf.st_mode) == 1)
    {
      printf("%ld %s\n", buf.st_size, pDirent->d_name);
    }

    // printf("%ld %s\n", buf.st_size, pDirent->d_name);
    // printf("%s\n",pDirent->d_name);
  }

  // Close directory
  closedir(pDir);

  return 0;
}