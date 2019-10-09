#include <stdio.h>
#include <dirent.h>




/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char *dirname;

  if (argc == 1) {
    dirname = ".";
  } else if (argc == 2)  {
    dirname = argv[1];
  } else {
    fprintf(stderr, "You must provide a valid directory name.\n");
    exit(1);
  }
  // Open directory
  DIR * d = opendir(dirname);

  if (d == NULL) {
    fprintf(stderr, "directory cannot be opened.");
    exit(2);
  }
  struct dirent *entry;

  // Repeatly read and print entries
  
  while ((entry = readdir(d)) != NULL) {
    printf("%s\n", entry->d_name);
  }

  // Close directory
  closedir(d);

  return 0;
}
