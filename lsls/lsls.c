#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{

  char *dirname;
  // Parse command

  if (argc == 1)
  {
    dirname = ".";
  }
  else if (argc == 2)
  {
    dirname = argv[1];
  }
  else
  {
    fprintf(stderr, "usage: lsls [dir]\n");
    exit(1);
  }

  // Open directory
  DIR *d = opendir(dirname);

  if (d == NULL)
  {
    fprintf(stderr, "lsls: cannot open %s\n", dirname);
    exit(2);
  }

  // Repeatly read and print entries
  struct dirent *ent;

  while ((ent = readdir(d)) != NULL)
  {
    printf("%s\n", ent->d_name);
  }

  // Close directory
  closedir(d);

  return 0;
}

// int main(int argc, char **argv)
// {
//   Parse command line
//   DIR *dir;
//   struct dirent *sd;

//   Open directory
//   dir = opendir(".");

//   if (dir == NULL)
//   {
//     printf("Error! Cant open directory. \n");
//     exit(1);
//   }

//   Repeatly read and print entries

//   while ((sd = readdir(dir)) != NULL)
//   {
//     printf(">> %s\n", sd->d_name);
//   }

//   Close directory
//   closedir(dir);

//   return 0;
// }