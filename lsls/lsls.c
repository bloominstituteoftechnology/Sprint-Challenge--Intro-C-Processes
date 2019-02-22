#include <stdio.h>
#include <dirent.h>

/*******
* Main *
*******/

// function to print current working directory

// function to take new command

int main(int argc, char **argv)
// figure out  what to do with argc and argv
{
  while (1)
  {
    // Create command line instance ?
    // perhaps store variable to parse here

    // Parse command line
    // Create function to parse the command line
    // take string and check against predefined strings to see if they match
    // handle unrecognize commands

    // Open directory
    // opendir(); // http://man7.org/linux/man-pages/man3/opendir.3.html
    // change active directory

    // Repeatly read and print entries
    // readdir(3); // http://pubs.opengroup.org/onlinepubs/7908799/xsh/readdir.html
    // display active directory
    // for loop to read and print all file names and their sizes

    // Close directory
    // closedir(); // http://pubs.opengroup.org/onlinepubs/007904975/functions/closedir.html
  }
  return 0;
}