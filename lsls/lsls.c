#include <stdio.h>
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
struct stat st;

DIR *dir;
struct dirent *ent;
if ((dir = opendir (b2)) != NULL) {
  // Repeatly read and print entries
  while ((ent = readdir (dir)) != NULL) {
  // use stat to pull file size in bytes. then print
  stat(ent->d_name, &st);
  printf ("%10lld  ", st.st_size);
  printf ("%s\n", ent->d_name);

  }
  // Close directory
  closedir (dir);
 
  return 0;
}}

// struct stat st;
// stat(filename, &st);
// size = st.st_size;