#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
	DIR *dr;
	struct dirent *de;

	if (argc == 1) {
    dr = opendir(".");
  }
  else if (argc == 2) {
    dr = opendir(argv[1]);
  }
  else {
    fprintf(stderr, "Something gone wrong\n");
}

  if (dr == NULL) {
    fprintf(stderr, "Could not open current directory\n");
    exit(1);
  }
  else {
  // Repeatly read and print entries
   while ((de = readdir(dr)) != NULL) 
            printf("%s\n", de->d_name);
    }
  // Close directory
  closedir(dr);
  return 0;
}