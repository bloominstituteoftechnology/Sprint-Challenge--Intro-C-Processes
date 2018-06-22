#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  char *str;
  char* cmdpath;
  DIR *d;
  struct dirent *ent;
  struct stat buf;

  // Parse command line
  if (argc == 1) {
    char home[2] = ".";
    str = home;
  }
  else if (argc == 2) {
    str = argv[1];
  }
  else {
    fprintf(stderr, "Nope Unsuccseful\n");
    exit(1);
  }

  // Open directory
  d = opendir(str);
  if (d == NULL) {
    fprintf(stderr, "Error Opendir Unsuccesful\n");
    exit(1);
  }
  else {
  // Repeatly read and print entries
    ent = readdir(d);
    while (ent != NULL) {
      size_t len = strlen(str);
      size_t len2 = strlen(ent->d_name);
      char *str2 = malloc(len + 1 + len2 + 1 );
      strcpy(str2, str);
      str2[len] = '/';
      strcat(str2, ent->d_name);
      stat(str2, &buf);
      memset(str2, 0, sizeof(int));
      printf("%lld     ", buf.st_size);
      printf("%s\n", ent->d_name);
      ent = readdir(d);
    }
  }
  // Close directory
  closedir(d);
  return 0;
}