#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  struct dirent *de;
  DIR *d;

  if (argv[1] != '\0'){
    d = opendir(argv[1]);
  } else {
  d = opendir(".");
  }

  //printf("%s\n", argv);
  //printf("%s\n", argv[1]);


  /* print the i-node and name for each file: */
  while((de = readdir(d)) != NULL)
      printf("%s\n", de->d_name);

  closedir(d);

  return 0;
}
  // Parse command line

  // Open directory

  // Repeatly read and print entries

  // Close directory