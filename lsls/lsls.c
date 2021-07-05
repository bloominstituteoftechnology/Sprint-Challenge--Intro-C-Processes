#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
/**
 * Main
 */
int main(int argc, char **argv)
{

  // printf("===> hello lsls. \n");
  // printf("===>main process:  %d \n", (int)getpid());

  for (int i = 0; i < argc; i++)
  {

    printf(" arguments : %s \n", argv[i]);
  }
  printf(" argument 1  : %s \n", argv[1]);
  ///////////////
  int rc = fork();
  printf("*****(rc:%d) \n", rc);
  ////////////////////////////////
  if (rc < 0)
  {
    fprintf(stderr, " fork failed \n");

    exit(1);
  }
  else if (rc == 0)
  {

    printf("=======> child here (pid:%d)\n", (int)getpid());
    printf("hello \n");

    // char *array[] = {"ls", "-l", NULL};   ls
    // execvp(array[0], array);
    ///////////////////////////////////////
    // char *array[] = {"pwd", NULL};       pwd
    // execvp(array[0], array);
    //////////////////////////////////////////
    // char *array[] = {"./try", NULL};
    // execvp(array[0], array);
    ////////////////////////////////////////////  ls
    DIR *dir;
    struct dirent *sd;
    struct stat buff;

    if (argv[1] == NULL)
    {
      dir = opendir(".");
    }
    else
    {
      dir = opendir(argv[1]);
    }
    //dir = opendir(".");

    if (dir == NULL)
    {
      printf("error unable to open dir \n");
      exit(1);
    }

    while ((sd = readdir(dir)) != NULL)
    {
      printf("=== name of file: %s \n", sd->d_name);
      stat(sd->d_name, &buff);

      printf("=== size of file:  %lld \t ", buff.st_size);
    }

    closedir(dir);

    /////////////////////////    stat()

    exit(0);
  }
  else
  {
    // int wc = waitpid(rc, NULL, 0);
    wait(NULL);
    printf("========>parent here (pid: %d)  of child  (rc:%d)\n", (int)getpid(), rc);
    printf("goodbay \n");
  }

  return 0;
}