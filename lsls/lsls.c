#include <stdio.h>
#include <dirent.h>

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
DIR *dir;
struct dirent *ent;
if ((dir = opendir (b2)) != NULL) {
  // Repeatly read and print entries
  while ((ent = readdir (dir)) != NULL) {
  printf ("%s\n", ent->d_name);
  }
  // Close directory
  closedir (dir);
 
  return 0;
}}