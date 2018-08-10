#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{

  int len;
  struct dirent *Dirent;
  DIR *Dir;
  struct stat buf;

  if (argc < 2) {
      printf ("Usage: testprog <dirname>\n");
      return 1;
  }
  Dir = opendir (argv);
  if (Dir == NULL) {
      printf ("Cannot open directory '%s'\n", argv);
      return 1;
  }

  // while ((Dirent = readdir(Dir)) != NULL) {
  //     printf ("[%s]\n", Dirent->d_name);
  // }

  for (Dirent = readdir(Dir); Dirent != NULL; Dirent = readdir(Dir)) {
    len = stat(Dirent->d_name, &buf);
    if (len < 0) {
      fprintf(stderr, "%s not found\n", Dirent->d_name);
    } else {
      printf("%s %lld\n", Dirent->d_name, buf.st_size);
    }
  }

  closedir (Dir);
  return 0;

}

