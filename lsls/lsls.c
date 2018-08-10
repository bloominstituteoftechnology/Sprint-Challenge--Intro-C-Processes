#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  int argLength = argc;
  char* boss = argv[1];
  char* period = ".";
  char* b2 = (argLength == 2) ? boss : period;
  
  
  // Open directory
  
  directory = opendir(pathname); // assign directory to pathname stream
   if (directory == NULL) {
    fprintf(stderr, "%s is not a valid pathname.\n", pathname);
    exit(-2); // exit if pathname is not valid
  }

  // Repeatly read and print entries
   while ((ent = readdir (dir)) != NULL) {
  stat(ent->d_name, &st);
  printf ("%10lld  ", st.st_size);
  printf ("%s\n", ent->d_name);
  
  
  // Close directory
  closedir(directory);
  return 0;
}
