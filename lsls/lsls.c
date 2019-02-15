#include <stdio.h>
#include <dirent.h>
  #include <sys/types.h>
   #include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  int i;
  char *path;
 
    if(argc > 2) {
      fprintf(stderr, "Passed too many arguments(%d), only require 2.\n", argc);
		  exit(1);
    }

    path = ".";

    if(argc == 2) {
      path = argv[1];
    }
    
    DIR *d = opendir(path);

    if (d == NULL) {
      fprintf(stderr, "Failed to open file.\n");
      exit(2);
    }

    struct dirent *ent;
    struct stat buf;
    char filename[200];

    ent = readdir(d);

    while(ent != NULL) {
      strcpy(filename, "./");
      strcat(filename, ent->d_name);
      stat(filename, &buf);
      if(&buf == -1) {
        fprintf(stderr, "Error when retrieving byte information");
        exit(3);
      }
      printf("%10lld   ", buf.st_size);
      printf("%s\n", ent->d_name);
      ent = readdir(d);
    }
    



  // Open directory

  // Repeatly read and print entries

  // Close directory

  return 0;
}