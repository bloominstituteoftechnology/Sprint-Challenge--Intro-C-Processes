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
	if (argc == 1) {
		dirname = ".";	
	
	}else if (argc == 2) {
		dirname = argv[1];

	}else {
		fprintf(stderr, "usage: ./lsls [dirname]\n");
		exit(1);
	}

  // Open directory
	struct dirent *ent;
 	DIR *d = opendir(dirname);
	
	if(dr == NULL) {
		printf("lsls: cannot open directory");
		exit(2);
	}

  // Repeatly read and print entries
	while ((ent = readdir(d)) != NULL) {
		printf("%s\n", ent -> d_name);
	}

// Close directory

closedir(d); 

  return 0;
}