#include <stdio.h>
#include <stdlib.h> //brought in this
#include <dirent.h>
// #include <sys/stat.h> //NOTE: Add in for STRETCH

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  DIR *dir; //* = pointer
  struct dirent *dp;
  char *filename = "."; 

  if(argc == 2) { 
    filename = argv[1]; //1st argument = 1
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
// REMOVED--> replaced w/printf below    printf("%s\n", entry->d_name); //NOTE: %s = print string and \n = new line

//NOTE: be sure to include #systat at top
// STRETCH GOALS START HERE
// NOTE: Stat the entry
// NOTE: declare a buffer to hold the path string
  // char path[8196];
  // struct stat stat_buf;
  //NOTE: create the path using snprintf
  // snprintf(path, sizeof(path), "%s/%s", dirname, entry->d_name);
  // NOTE: call stat
  // if (stat(path, &stat_buf) < 0) {
  //   fprint(stderr, "failed to stat file %s\n", path);
  //   exit(3);
  // }

  // NOTE: print the filename and size
  // if (stat_buf.st_mode & S_IFREG) {
  //   printf("%10lld    %s\n", stat_buf.st_size, entry->d_name);
  // } else if (stat_buf.st_mode & S_IFDIR) {
  //   printf("%10s    %s\n", "<DIR>", entry->d_name);
  // } else {
  //   printf("%10s    %s\n", entry->d_name);
  //     }
// }

//   // NOTE: Close directory
//   closedir(d);

//   return 0;
// }