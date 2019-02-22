#include <stdio.h>
#include <dirent.h>

/*******
* Main *
*******/

// function to print current working directory

// function to execute command

int main(int argc, char **argv)
// figure out  what to do with argc and argv
{
  // int terminate = 0;
  // while (!terminate)
  // {

  // Create command line input
  // Pass input to Parse command line

  // Parse command line
  // utilize strcmp()
  // Create function to parse the command line
  // take string and check against predefined strings to see if they match
  // handle unrecognize commands

  // Open directory
  DIR *opendir(char *path);
  printf("%d\n", dir);
  // opendir(); // http://man7.org/linux/man-pages/man3/opendir.3.html
  // opens a dir stream that corresponds to the dir name
  // returns a pointer to the dir stream.
  // change active directory

  // Repeatly read and print entries
  struct dirent *readdir(DIR * d);
  // readdir(3); // http://pubs.opengroup.org/onlinepubs/7908799/xsh/readdir.html
  // function to display active directory
  // for loop to read and print all file names and their sizes

  // Close directory
  closedir(DIR * d);
  // closedir(); // http://pubs.opengroup.org/onlinepubs/007904975/functions/closedir.html
  // }
  return 0;
}