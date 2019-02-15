#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *d;
  char *directory;
  struct dirent *ent;
  ;
  // Parse command line
  if (argc > 1)
  {
    directory = argv[1];
  }

  // Open directory
  if (directory)
  {
    d = opendir(directory);
  }
  else
  {
    directory = ".";
    d = opendir(directory);
  }

  // Check for error opening directory
  if (d == NULL)
  {
    fprintf(stderr, "open directory error\n");
    exit(1);
  }

  printf("Size:     Name:\n");
  while ((ent = readdir(d)) != NULL)
  {
    char *file_path[100];

    //file path concatenates directory and file name
    strcpy(file_path, directory);
    strcat(file_path, "/");
    strcat(file_path, ent->d_name);

    struct stat buf;
    stat(file_path, &buf);

    printf("%lld     %s\n", buf.st_size, ent->d_name);
  }
  //Close directory
  closedir(d);

  return 0;
}