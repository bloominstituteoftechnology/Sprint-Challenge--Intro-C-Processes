#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
  struct stat buf;
  struct dirent *de;
  DIR *d;

  if (argv[1] != '\0'){
    d = opendir(argv[1]);
  } else {
    d = opendir(".");
  }

  char path[] = "./";

  while((de = readdir(d)) != NULL) {
      char * pathcpy = strdup(path);
      strcat(pathcpy, de->d_name);
      stat(pathcpy, &buf);
      //printf("Stat Files Test\n");
      switch(buf.st_mode & S_IFMT) {
        case S_IFREG:
            //printf("Regular File\n");
            printf("%7lld   %s\n",  buf.st_size, de->d_name);
            break;
        case S_IFDIR:
            //printf("Directory\n");
            printf("%7s   %s\n", "<DIR>", de->d_name);
            break;
    }

     // printf("%d\n", buf.st_mode);
      //printf("%lld %s\n",  buf.st_size, de->d_name);
  }

  closedir(d);

  return 0;
}