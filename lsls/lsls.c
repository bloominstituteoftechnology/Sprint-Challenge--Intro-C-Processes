#include <stdio.h>
#include <dirent.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  
  //char dir = *argv[argc - 1];
  printf("%s", argv[argc - 1]);
  printf("\n");
  // Open directory
  struct dirent *pDir;
  DIR *dir;
  dir = opendir (argv[1]);
  // Repeatly read and print entries
  int rc = fork();

  if (rc == 0) {
    while ((pDir = readdir(dir)) != NULL) {
      printf ("[%s]\t", pDir->d_name);
    }
    closedir(dir);
    return -1;
  } else if (rc != 0) {
    waitpid(rc, NULL, 0);
    printf("testing child should have called ls\n");
    return 0;
  }
  return 0;
  // Close directory

  return 0;
}