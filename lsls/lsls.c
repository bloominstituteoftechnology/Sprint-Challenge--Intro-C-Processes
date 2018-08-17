#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * Main
 */

// Although main takes arguments, it doesn't need to take in anything to run.
// argc=argument count, argv=accepts a string as input
int main(int argc, char **argv)
{
  // Parse command line
  // string variable to hold the name of a directory.
  char *dirname;
  // if argc == 1, there were no arguments given because
  // argc includes the name of the program itself.
  if (argc == 1) 
  {
    // set directory we are looking at to "."
    dirname = ".";
  }
  // If argc recieves an argument
  else if (argc == 2)
  {
    // take the recieved arguement and assign the it to the Directory Name.
    dirname = argv[1];
  }
  // otherwise, we recieved something else as input
  else 
  {
    // send a standard error with an exit code.
    // I've been thinking about this code block like a standard "catch" in JS.
    fprintf(stderr, "Usage: lsls [dirname]\n");
    // the '1' for the exit code doesn't have any special meaning,
    // it would normally just act as a pointer to where the error is occurring,
    // but in this case is even more irrelevant because of the stderr and message
    // we throw above ^ in the fprintf().
    exit(1);
  }
  // Open directory
  // DIR = a type representing a directory stream
  // it also defines the structure dirent, which we'll use below
  DIR *d = opendir(dirname);
  // error checking, if d is null, opening failed
  if (d == NULL)
  {
    // error handling with descriptive message
    fprintf(stderr, "lsls: cannot open directory %s\n", dirname);
    // return a different error code, to point to where the error is.
    exit(2);
  }
  // Repeatly read and print entries
  // we destructure dirent into entry
  struct dirent *entry;
  // Go through each diretory until there are none left
  while ((entry = readdir(d)) != NULL)
  {
    // stat the entry:
    // include sys/stat up top
    // get the full path that will be passed in as an argument
    // 8192 is an arbitrary number chosen because it is a power of 2
    char fullpath[8192];
    // format the full path
    // write the directories name in "%s/%s" format, onto the full path
    snprintf(fullpath, sizeof(fullpath), "%s/%s", dirname, entry->d_name);
    // define the stat as stat buffer
    struct stat stat_buf;
    // it will grab stats off of the full path and put it onto the address of stat_buf
    if (stat(fullpath, &stat_buf) < 0)
    {
      // descriptive error handling
      fprintf(stderr, "lsls: failed to stat file %s\n", fullpath);
      // exit with a '3' to point here, as explained above, this is kind of redundant, 
      // but it less simply less chars than return 1;
      exit(3);
    }
    // st_mode comes from the stat struct.
    // this is how we get the file size
    if (S_ISREG(stat_buf.st_mode))
    {
      // print the filesize 
      printf("%10lld is the filesize of %s\n", stat_buf.st_size, entry->d_name);
    }
    // if it's a directory, we dont care about the file size, so just let
    // the user know it is a DIR for directory
    else if(S_ISDIR(stat_buf.st_mode))
    {
      // print out the name of each directory
      // d_name comes from the dirent struct.
      printf("%10s %s\n", "<DIRECTORY>", entry->d_name);
    }
    else
    {
      // print the file size
      printf("%10s %s\n", "", entry->d_name);
    }
  }
  // Close directory
  closedir(d);
  // end the 'main' block
  return 0;
}
