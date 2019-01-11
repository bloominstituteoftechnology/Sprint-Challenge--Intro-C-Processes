#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  int i;
  int length = argc - 1;
  char *commands[length];
  char *path;

  for(i = 1; i< argc; i++){
  	commands[i-1] = argv[i];	
  }

  // Open directory
  DIR *dir;

  if (length == 0){
  	//default
  	path = "./";
  	// dir = opendir(".");
  } else if (length == 1 ){
  	//path specified
  	path = commands[length-1];
  	// dir = opendir(path);
  } else {
  	//too many arguments provided
  	path = commands[length-1];
  	// dir = opendir(path);
   	printf("More arguments provided then expected");
  }
 	
 	dir = opendir(path);

  if (dir == NULL){
  	printf("Error: Directory not found/n");
  	exit(1);
  }

  // Repeatly read and print entries
  struct dirent *ent = readdir(dir);
  char full_path[200];
  char *name;
  struct stat buf;
  
  while(ent != NULL){
		name = ent->d_name;  	
		strcpy(full_path,path);
		strcat(full_path,"/");
		strcat(full_path,name);
		stat(full_path, &buf);
		printf("%10lld ", buf.st_size);
  	printf("    %s\n", ent->d_name);
  	ent = readdir(dir);
  }
  // Close directory
  closedir(dir);
  return 0;
}