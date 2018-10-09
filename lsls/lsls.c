#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{

  // Parse command line
  char *dirname;

//debug 

  // int i;

  //   printf("There are %d command line argument(s):\n", argc);

  //   for (i = 0; i < argc; i++) {
  //       printf("   %s\n", argv[i]);
  //   }
 ///end debug
  if(argc >2)
  {
    printf("Error: Too many command line arguments \n");
    exit(1);
  }
  else if(argc == 1)
  {
    dirname = ".";
  }
  else {
    dirname = argv[1];
  }
 
  // Open directory

  DIR *d= opendir(dirname);
 // printf("Debug: %p\n", d);

  if(d == NULL)
  {
    printf("Error: Directory not found.\n");
    exit(1);
  }
  // Repeatly read and print entries
  struct dirent *ent;
  ent = readdir(d);
  while(ent != NULL)
{

  printf("%s\n", ent->d_name);
  // ent++;
  ent = readdir(d);

}
  // Close directory
  closedir(d);
  return 0;
}