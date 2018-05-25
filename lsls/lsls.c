#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  struct dirent *dp; // pointer to "dirent"
  if (argc > 1)
  {
    char *arrOfArgs[3];               // pointer to array of chars
    arrOfArgs[0] = strdup("/bin/ls"); // list program ls
    arrOfArgs[1] = strdup(argv[v]);
    arrOfArgs[2] = NULL;
    execvp(arrOfArgs[0], arrOfArgs) // left argument what is ran right argument for that functions parameters
  }
  else
  {
    DIR *dr = opendir(".");
    if (dr == NULL)
    {
      printf("Could not open current directory");
      return 0;
    }
    while ((dp = readdir(dr)) != NULL)) printf("%s\n",dp->d_name);

    closedir(dr);
  }

  return 0;
}

/*
structs.. functions.. etc..

dirent

strdup

execvp

opendir

*/