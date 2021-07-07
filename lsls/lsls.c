#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

/**
 * Main
 */

int main(int argc, char **argv)
{
  struct dirent *plzwork;

  DIR *test;
 
  if (argc==2) {

  if ((test=opendir(argv[1])) != NULL) {

  while ((plzwork=readdir(test)) != NULL) {
          struct stat buf;
          char subdir[1028] = "";
          strcat(subdir, argv[1]);

  if (argv[1][strlen(argv[1])-1]!='/')
    {
      strcat(subdir,"/");
    }
      strcat(subdir, plzwork->d_name);
      strcat(subdir,"\0");
      stat(subdir, &buf);

  if ((buf.st_mode & S_IFDIR)!=0) {
      printf("firing off v1 <DIR> %s\n", plzwork->d_name);

  } else {
      printf("%lld %s\n", buf.st_size, plzwork->d_name);
    }
  }

  closedir(test);
    } else {
      exit(-1);
    }

    } else if (argc==1) {

  if ((test=opendir("./")) != NULL) {

  while ((plzwork=readdir(test)) != NULL) {
    struct stat buf;
    char subdir[1028] = "";
      strcat(subdir, "./");
      strcat(subdir, plzwork->d_name);
      strcat(subdir,"\0");
      stat(subdir, &buf);

  if ((buf.st_mode & S_IFDIR)!=0) {
    printf("firing off v2 <DIR> %s\n", plzwork->d_name);

  } else {
      printf("%lld %s\n", buf.st_size, plzwork->d_name);
    }
  }

  closedir(test);
    } else {
      exit(-1);
    }
  }
  return 0;
}