#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *directory;
  struct dirent *entry;
  directory = opendir(argv[1]);
  if (directory == NULL) {
    printf("Cannot open directory '%s'\n", directory);
    return 1;
  }
  rc = fork();
  if(rc < 0) {
    fprintf(stderr, "Fork failed \n");
    exit(1)
  } else if(rc == 0) {
    while ((entry = readdir(directory)) != NULL) {
      printf("%s \n", entry->d_name);  
    }
  } else {
    int wc = waitpid(rc, NULL, 0);
    closedir(directory);
  }



  return 0;
}