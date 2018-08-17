#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  char *dirname; // if some argument path is ame, store it in pointer
  // Parse command line
  if(argc == 1){ // if argc is 1, then no arguments were given
    // set the directory that we're going looking at to "."
    dirname = ".";
  } else if (argc == 2) {
    dirname = argv[1]; //set name to be name of our program
  } else {
    fprintf(stderr, "usage: lsls [dirname]\n");
    exit(1);
  }

  // Open directory
  // when making a reference to a structure, you are likely to be using a pointer
  DIR *d = opendir(dirname);

  if (d == NULL){ // if opendir fails
    fprintf(stderr, "lsls: cannot open directory %s\n", dirname);
    exit(2); // exit with different exit code to specify which exit() is being called
  }

  // Repeatly read and print entries
  struct dirent *entry;

  while((entry = readdir(d)) != NULL) { // while entry isn't returning null
    // stat the entry
    char fullpath[8192];
    snprintf(fullpath, sizeof(fullpath), "%s/%s", dirname, entry->d_name); // write this data to the fullpath buffer
    struct stat stat_buf; //initializes empty structures

    //looks at sie of file, and stores that data in the address where the stat_buf is
    if(stat(fullpath, &stat_buf) < 0) { //  pass in the fullpath data to the address for stat_buf
      fprintf(stderr, "lsls: failed to stat file %s\n", fullpath);
      exit(3);
    } 
    printf("%lld %s\n", stat_buf.st_size, entry->d_name); // print the address that entry points to. '->' is similar to dot nottion
  }

  // Close directory
  closedir(d);

  return 0;
}