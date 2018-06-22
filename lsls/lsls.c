#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse Command Line
  DIR *dir;
  char *currentDir;
  struct dirent *ent;
  struct stat buf;

  if (argc > 1) {
    currentDir = argv[1];
  } else {
    currentDir = ".";
  }

  // Opening Directory
  dir = opendir(currentDir);
  if (dir == NULL) {
    fprintf(stderr, "Try again\n");
    exit(1);
  } else {
    
  // Repeatedly read and print entries
  while ((ent = readdir(dir)) != NULL) {
    stat(ent->d_name, &buf);
    if ((buf.st_mode & S_IFDIR) != 0) {
      printf("%10s %s\n", "<DIR>", ent->d_name);
    }
  }

  // Close Directory
    closedir(dir);
  }
  return 0;
}