#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  struct dirent *de;
  DIR *dr;
  char str;

  if (argc > 1) {
    str = argv[1];
  } else {
    str = ".";
  }


  if ((dr = opendir(str)) == NULL)
  {
    printf("Could not open current directory");
    return 0;
  } else {

  while ((de = readdir(dr)) != NULL)
    printf("%s\n", de->d_name);

  closedir(dr);
  return 0;
}
}