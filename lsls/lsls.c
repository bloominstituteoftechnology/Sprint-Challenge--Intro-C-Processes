#include <stdio.h>
#include <dirent.h>
#include <string.h>
# include <sys/stat.h>
# include <stdlib.h>
/**
 * Main
 */
//PR Text

char* concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
    // in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

int main(int argc, char **argv)
{
  // Parse command line

  DIR *dir;
 
  
  struct dirent *sd;
  struct stat buf;

  dir = (argc < 2) ? opendir("./") : opendir(*(argv+1));

  if(dir == NULL){
    printf("Nice try OMEGALUL");
  }
  
  while( (sd=readdir(dir)) != NULL){    
    
    int error = stat((concat(argv[1] ? argv[1] : "./",sd->d_name)), &buf);
    if(error == -1){
      printf("error");
      printf("\n%s",concat(argv[1],sd->d_name));
    }
    printf("\n%ld", buf.st_size);
    printf("              ");
    printf("%s\n", sd->d_name);
  }




  closedir(dir);
  // Open directory

  // Repeatly read and print entries

  // Close directory

  return 0;
}