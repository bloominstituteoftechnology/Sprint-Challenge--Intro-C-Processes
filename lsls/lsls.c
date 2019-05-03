#include <stdio.h>
#include <dirent.h>
#include <string.h>
# include <sys/stat.h>
# include <stdlib.h>

char* concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1);
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

int main(int argc, char **argv)
{
  DIR *dir;  
  struct dirent *sd;
  struct stat buf;

  dir = !argv[1]? opendir("./") : opendir(*(argv+1));

  if(dir == NULL){
    printf("Nice try OMEGALUL");
  }
  
  while( (sd=readdir(dir)) != NULL){    
    char* s = concat(argv[1] ? argv[1] : "./",sd->d_name);
    int error = stat(s, &buf);
    if(error == -1){
      printf("error");
      printf("\n%s",concat(argv[1],sd->d_name));
    }
    printf("\n%ld", buf.st_size);
    printf("              ");
    printf("%s\n", sd->d_name);
    free(s);
  }
  closedir(dir);
  return 0;
}