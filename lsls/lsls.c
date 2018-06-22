#include <stdio.h>
#include <stdlib.h> //brought in this
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  DIR *dir;
  struct dirent *dp;
  char *filename = ".";

  if(argc == 2) {
    filename = argv[1];
  } 
  else if (argc > 2) 
    {
    fprintf(stderr, "Only contents of one directory can be shown at a time.\n");
  }

  // Open directory
  if ((dir = opendir(filename)) == NULL) {
    printf (stderr, "Error! Cannot Open Directory.\n");
    exit(1);
  }

  // Repeatly read and print entries
  while ((dp = readdir(dir)) != NULL) {
    printf ("%s\n", dp->d_name);
  }

  // Close directory
  closedir(dir);

  return 0;
}

//-----------------------------------------------------

//instructor solve

// int main(int argc, char **argv)
// {
//   char *dirname;
//   // NOTE: Parse command line
//   // NOTE: no args were passed to the program
//   if (argc == 1) {
//     dirname - "."; //NOTE: . = current directory
//     } else if (argc == 2) {
//       dirname = argv[1];
//     } else {
//       fprintf(stderr, "usage: ./lsls [dirname]\n");
//       exit(1); //NOTE: can also return(1);
//     }

//   // NOTE: Open directory
//   DIR *d = opendir(dirname);

//   // NOTE: Error check on opening the directory
//   if (d == NULL) {
//     fprintf(stderr, "./lsls: cannot open directory %s\n", dirname);
//     exit(2);
//   }

//   // NOTE: Repeatly read and print entries
//   struct dirent *entry;
  
//   while ((entry = readdir(d)) != NULL) {
//     printf("%s\n", entry->d_name); //NOTE: %s = print string and \n = new line
//   }

//   // NOTE: Close directory
//   closedir(d);

//   return 0;
// }