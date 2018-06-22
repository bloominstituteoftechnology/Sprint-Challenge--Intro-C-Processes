#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char *dirname;
  //lets check the number of arguments passed into the ls command
  
  if (argc == 1) {
  //all that's inside is lsls
  //no args were passed into the program  
  dirname = ".";
  } else if (argc == 2) {
    dirname = argv[1];
  } else {
    fprintf(stderr, "usage: .lsls [dirname]\n");
    exit(1);
  }

  // Open directory
    DIR *dr = opendir(dirname);
    if (dr == NULL) {
      printf("./lsls: Could not open current directory %s\n", dirname);
      exit(2);
    }

  // Repeatly read and print entries
    struct dirent *entry;

    while ((entry = readdir(dr)) != NULL) {
      printf("%s\n", entry -> d_name);
    }
    
  // Close directory
  closedir(dr);
  return 0;
}