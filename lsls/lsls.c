#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
	char *dir_arg;
	if (argc == 1) {
		dir_arg = ".";	
	}
	else if (argc == 2) {
		dir_arg = argv[1];
	}
	else {
		fprintf(stderr, "Too many arguments were passed. Please try again");
		exit(1);
	}

  // Open directory
	struct dirent *ent;
	printf("Directory:%s\n", dir_arg);
	DIR *dr = opendir(dir_arg);
	
	if(dr == NULL) {
		printf("There was an error opening/finding the current directory.");
		exit(1);
	}

  // Repeatly read and print entries
	while ((ent = readdir(dr)) != NULL) {
		printf("%s\n", ent -> d_name);
	}

// Close directory

closedir(dr); 

  return 0;
}