#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  struct dirent *dp;
  // Parse command line
  if (argc > 1)
  {
    char *myargs[3]; // allocate an array of chars to hold 3 bytes
    // `strdup` duplicates the given input string
    myargs[0] = strdup("/bin/ls");
    myargs[1] = strdup(argv[1]);
    myargs[2] = NULL;
    execvp(myargs[0], myargs); // runs list dir program, passing in the `myargs` array to the list dir program as arguments
    printf("this should not be seen. %s", argv[1]);
  }
  else
  {

    DIR *dr = opendir(".");

    if (dr == NULL)
    {
      printf("Could not open current directory");
      return 0;
    }
    // Repeatly read and print entries
    while ((dp = readdir(dr)) != NULL)
      printf("%s\n", dp->d_name);

    closedir(dr);
  }

  return 0;
}
