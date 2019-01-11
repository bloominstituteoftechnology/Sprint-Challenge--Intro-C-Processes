#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
  struct stat buf;
  struct stat buf1;
  struct dirent *de;
  struct dirent *fe;
  DIR *d;
  DIR *f;

  if (argv[1] != NULL){
    d = opendir(argv[1]);
  } else {
    d = opendir(".");
  }

  char path[] = "./";

  while((de = readdir(d)) != NULL) {
      char * pathcpy = strdup(path);
      strcat(pathcpy, de->d_name);
      stat(pathcpy, &buf);

      switch(buf.st_mode & S_IFMT) {
        case S_IFREG:
            printf("%7lld   %s\n",  buf.st_size, de->d_name);
            break;
        case S_IFDIR:
            printf("%7s   %s\n", "<DIR>", de->d_name);
            f = opendir(de->d_name);

            while ((fe = readdir(f)) != NULL){
              char * pathcpy1 = strdup(pathcpy);
              strcat(pathcpy1, "/");
              strcat(pathcpy1, fe->d_name);
              stat(pathcpy1, &buf1);
              switch(buf1.st_mode & S_IFMT) {
                case S_IFREG:
                  printf("%20lld   %s\n",  buf1.st_size, fe->d_name);
                  break;
                case S_IFDIR:
                  printf("%20s   %s\n", "<DIR>", fe->d_name);
                  break;
              }
            }
            break;
      }
  }

  closedir(d);

  return 0;
}