#include <stdio.h>
#include <dirent.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  printf("%d\n", argc);
  printf("argv0: %s\n", argv[0]);
  printf("argv1: %s\n", argv[1]);
  // Parse command line
  char *args[] = {argv[1], NULL};

  // Open directory
  int rc = fork();
  if(rc<0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    DIR *myDir = opendir(argv[1]);
    if(myDir == NULL){
      fprintf(stderr, "opendir failed\n");
    }

  // Repeatly read and print entries
  struct dirent *ent;
  // while(something) {
  //   ent = readdir(d);
  //   printf("%s\n", ent.d_name);
  // }
    

  // Close directory
    int closedir(DIR *myDir);



  } else {
    int wc = wait(NULL);
    printf("parent finished");
  }



  return 0;
}