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
    printf("more than one command!\n");
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

  // Repeatly read and print entries

  if (d == NULL)
  {
    fprintf(stderr, "open directory error\n");
    exit(1);
  }

  //printf("%s\n", ent->d_name);
  printf("Size:     Name:\n");
  while ((ent = readdir(d)) != NULL)
  {
    char *src[50];
    char *file_path[100];
    strcpy(file_path, directory);
    strcat(file_path, "/");
    strcat(file_path, ent->d_name);

    struct stat buf;
    stat(file_path, &buf);

    //char *file_path = strcat(directory, "/" ,ent->d_name);
    printf("%lld     %s\n", buf.st_size, ent->d_name);
  }
  //Close directory
  closedir(d);

  return 0;
}