
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>



/* int main(int argc, char **argv) */
int main(int argc, char **argv)
{
  // Parse command line
  struct dirent *dirent;
  DIR *dir;

  struct stat buf;

  if (argv[1] != NULL) {
    printf("%d is argc", argc);
    dir = opendir(argv[1]);
  }
  else {
    dir = opendir(".");
  }
  char filepath[] = "./";

  while ((dirent = readdir(dir)) != NULL) {
    /* printf("[%s]\n", dirent -> d_name); */
    char * pathcpy = strdup(filepath);
    strcat(pathcpy, dirent->d_name);
    stat(pathcpy, &buf);
    printf("%11ld %s\n", buf.st_size, dirent->d_name);
  }

  // Close directory
  closedir(dir);
  return 0;
}
