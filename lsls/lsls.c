#include <stdio.h>
#include <dirent.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
    //printing the directory that will be opened
  printf("%s", argv[1]);
  printf("\n");
  // Open directory
    //specifying the structer to be of type directory
  struct dirent *pDir;
  DIR *dir;
  dir = opendir(argv[1]);
  // Repeatly read and print entries
  char *dirFiles = argv[1];
  int rc = fork();

  if (rc == 0) {
    //looping threw the directory
    while ((pDir = readdir(dir)) != NULL) {
      //printing the names of the files
      printf("%s\n", pDir->d_name);
      //Printing the File Serial Numbers of the file
      printf("FSN: %llu\n", pDir->d_ino);
    }
    //closing the directory
    closedir(dir);
    return 0;
  } else if (rc != 0) {
    waitpid(rc, NULL, 0);
    printf("testing child should have called DIR\n");
    return 0;
  }
  return 0;
  // Close directory

  return 0;
}