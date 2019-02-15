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
    // Opens directory
    d = opendir(dirName);
  }
  if (argc > 2) {
    dirName = argv[1];
    // Opens directory
    d = opendir(dirName);
  }  
  if(d == NULL) {
    printf("Could not open directory '%s'\n", argv[1]);
  }
  
  
  // Repeatly read and print entries
  while((ent = readdir(d)) != NULL) {
    stat(ent -> d_name, &buf);
    printf("File size: %lld  Directory: %s\n", buf.st_size, ent -> d_name);
  }
  // Close directory
  closedir(d);
  return 0;

  // Modified code to kind of resemble the lecture code

  // char *dirName;
  // DIR *d;
  // struct dirent *ent;
  // struct stat buf;
  // // Parse command line
  // if(argc <= 1) {
  //   dirName = ".";
  // }
  // if (argc >= 2) {
  //   dirName = argv[1];
  // }

  // // Open directory
  // d = opendir(dirName);
  // if(d == NULL) {
  //   printf("Could not open directory '%s'\n", argv[1]);	
  // }

  
  // // Repeatly read and print entries
  // while((ent = readdir(d)) != NULL) {
  //   char fullpath[4096];
  //   snprintf(fullpath, sizeof(fullpath), "%s/%s", dirName, ent -> d_name);
  //   if(stat(ent -> d_name, &buf) < 0) {
  //     fprintf(stderr, "failed to stat file %s\n", fullpath);
  //   }
  //   printf("File size: %10lld  Directory: %s\n", buf.st_size, ent -> d_name);
  // }
  // // Close directory
  // closedir(d);
  // return 0;
}