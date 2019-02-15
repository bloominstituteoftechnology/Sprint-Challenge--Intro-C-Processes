#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  char *dirName;
  DIR *d;
  struct dirent *ent;
  struct stat buf;
  // Parse command line
  if(argc < 2) {
    dirName = ".";
    d = opendir(dirName);
  } else if (argc > 2) {
    dirName = argv[1];
    // Open directory
    d = opendir(dirName);
  } else {
    if(d == NULL) {
      printf("Could not open directory '%s'\n", argv[1]);
      exit(1);
    }
  }
  
  // Repeatly read and print entries
  while((ent = readdir(d)) != NULL) {
    stat(ent -> d_name, &buf);
    printf("File size: %lld  Directory: %s\n", buf.st_size, ent -> d_name);
  }
  // Close directory
  closedir(d);
  return 0;
}