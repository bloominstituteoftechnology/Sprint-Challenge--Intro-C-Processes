#include <stdio.h>  // install the necessary libraries
#include <stdlib.h> // to call the exit function
#include <dirent.h> // holds the declarations for DIR, struct dirent, opendir(), readdir(), and closedir()

//Stretch Goals
#include <sys/stat.h>   // calls the stat functions

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char *dir_name; // initialize the directory
  if (argc == 1) {  // no argument/path was received; argc default is 1
    dir_name = "."; // set the directory to "."
  } else if (argc == 2) { // if an argument/path was received (bec argc > default 1)
    dir_name = argv[1]; // set the directory to 1 which is the path; 0 is assigned for the lsls path
  } else {
    fprintf(stderr, "There is an error. Use this format: lsls [directory_name]\n"); // in case of error, print this error message
    exit(1);  // exit with code 1
  }

  // Open directory
  DIR *directory = opendir(dir_name);  // assign handle/name of the directory we are opening

  // error checking
  if (directory == NULL) {  // if there's an error opening the directory
    fprintf(stderr, "Cannot open this directory %s\n", dir_name); // print error message 
    exit(2);  // exit with code 2 to identify error is from opening directory
  }

  // Repeatly read and print entries
  struct dirent *entry; // define a direct struct called entry

  while ((entry = readdir(directory)) != NULL) {  // while loop that if not NULL, there are more entries to read; while loop runs until entry == NULL  
    
    // Stretch - Stat the entry
    char fullpath[8186];    // initialize another buffer passing an arbitrary number
    snprintf(fullpath, sizeof(fullpath), "%s/%s", dir_name, entry->d_name);  // format the fullpath and pass in the stat function; this is the format that stat requires
    struct stat stat_buf;   // initialize stat buf 
    
    // error handling
    if (stat(fullpath, &stat_buf) < 0) {   // this will stat the fullpath buffer/ given file and store it at the address of the stat_buf
        fprintf(stderr, "Failed to stat the file %s\n", fullpath);  // error message
        exit(3);    // exit with code 3
    }

    if (S_ISREG(stat_buf.st_mode)) {  // if regular file  
      printf("%10lld %s\n", stat_buf.st_size, entry->d_name); // print entries and their file sizes: passing in lld (long long digits) and 10 to format 10 spaces, st_size to return the file sizes in bytes 
    } else if (S_ISDIR(stat_buf.st_mode)) { // if file is a directory (represented by "." or "..")
      printf("%10s %s\n", "<DIR>", entry->d_name);  // replace the "." or ".." with <DIR>; added 10 to format 10 spaces
    } else {  
      printf("%10s %s\n", "", entry->d_name); // for anything else, print an empty string; added 10 to format 10 spaces
    }
  }

  // Close directory
  closedir(directory);  // calling the closedir() function passing in the directory

  return 0;
}