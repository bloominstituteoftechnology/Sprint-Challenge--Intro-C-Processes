#include <stdio.h>
#include <dirent.h>
/**
 * Main
 */

//<<<<<<<<  >>>>>>> <<<<< >>>>>>>>> <<<<  >>>>>
int listdir(const char *path)
{
  struct dirent *lsls;
  DIR *lspointer;

  lspointer = opendir(path);
  if (lspointer == NULL)
  {
    fprintf(stderr, "Opendir failed");
    //exit() doesn't seem to work here, needs <stdlib.h>
    return -1;
  }

  while ((lsls = readdir(lspointer)))
    
    puts(lsls->d_name);//For output, you should print the field `d_name` 
    //from your `struct dirent *`
    // puts(lsls->d_ino);
    // puts(lsls->d_off);
    // puts(lsls->d_reclen);
    // puts(lsls->d_type);

  closedir(lspointer);
  return 0;
}

int main(int argc, char **argv)
{
  int counter = 1;

  if (argc == 1)
    listdir(".");
  //if argc > 1, then ++counter == 2, 2 <= 2 is true 
  //argc will be as big as the arguments, counter will increment by one 
  // until the condition doesn't match, meaning couter is greater than argc

  while (++counter <= argc)
  {
    // printfs with the -la flag, the -a flag prints hidden files
    //the -l flag alone doesn't print hidden files
    printf("%d %s\n", argv[counter - 1]);
    listdir(argv[counter - 1]);
  }

  return 0;
}