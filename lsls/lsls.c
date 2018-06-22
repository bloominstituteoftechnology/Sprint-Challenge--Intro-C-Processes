#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  struct dirent *pDirent;
  DIR *pDir;

  // Parse command line
  // Open directory
  if (argc == 1) //no directory given, only ./lsls.exe was called
  {
    pDir = opendir(".");
  }
  else if (argc == 2) // a directory was given, 2nd index ([1]) is the directory
  {
    pDir = opendir(argv[1]);
  }
  else // incorrect usage of ./lsls.exe
  {
    printf("Usage: ./lsls.exe <directory name>\n");
    return 1;
  }

  if (pDir == NULL) //checks if the directory is null
  {
    printf("Can't open dir %s \n", argv[1]);
    return 1;
  }

  while ((pDirent = readdir(pDir)) != NULL)  //until hte entire directory is iterated through
  {
    printf("[%s]\n", pDirent->d_name);
  }

  // Repeatly read and print entries

  
  // while ((pDirent = readdir(pDir)) != NULL) //until hte entire directory is iterated through
  // {
  //   stat(pDirent->d_name, &buffer);

  //   if (S_ISREG(buffer.st_mode))
  //   {
  //     printf("%11111111s [%s]\n", buffer.st_size, pDirent->d_name);
  //   }
  //   else if (S_ISDIR(buffer.st_mode))
  //   {
  //     printf("%10s [%s]\n", "<DIR>", pDirent->d_name);
  //   }
  //   else
  //   {
  //     printf("%10s [%s]\n", "<other>", pDirent->d_name);
  //   }
  // }

  // Close directory
  closedir(pDir);

  return 0;
}