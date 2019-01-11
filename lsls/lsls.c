#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  int i;
  int length = argc - 1;
  char *commands[length];

  for(i = 1; i< argc; i++){
  	commands[i-1] = argv[i];	
  }

  // Open directory
  DIR *dir;

  if (length == 0){
  	//default
  	dir = opendir(".");
  } else if (length == 1 ){
  	//path specified
  	dir = opendir(commands[length-1]);
  } else {
  	//too many arguments provided
  	dir = opendir(commands[length-1]);
  	printf("More arguments provided then expected");
  }
 
  if (dir == NULL){
  	printf("Error: Directory not found");
  	exit(1);
  }

  // Repeatly read and print entries
  struct dirent *ent = readdir(dir);

  while(ent != NULL){
  	printf("%s\n", ent->d_name);
  	ent = readdir(dir);
  }
  // Close directory
  closedir(dir);
  return 0;
}