#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
    char *dirname;
  // Parse command line
    if (argc >= 2) {
      dirname = argv[1];
    } else {
      dirname = ".";
    }


  // Open directory
    DIR *d = opendir(dirname);

  // Repeatly read and print entries
    struct dirent *de;

    while ((de = readdir(d)) != NULL) {
      struct stat buf;
      int total_bytes = strlen(dirname) + strlen(de->d_name) + 1 + 1;

      char *fullpath = malloc(total_bytes);
      
      sprintf(fullpath, "%s/%s", dirname, de->d_name);

      if(stat(fullpath, &buf) == -1) {
          perror("stat");
          continue;
      }

      free(fullpath);

      printf("%10lld %s\n", buf.st_size, de->d_name);
  }

  // Close directory

  return 0;
}
