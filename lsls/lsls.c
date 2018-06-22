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

  // Repeatly read and print entries
  const char *ls = "/bin/ls";
  int rc = fork();

  if (rc == 0) {
    execvp(ls, &argv[argc - 1]);
    printf("you shouldnt be seeing this");
    return -1;
  } else if (rc != 0) {
    waitpid(rc, NULL, 0);
    printf("testing child should have called ls");
    return 0;
  }
  return 0;
  // Close directory

  return 0;
}