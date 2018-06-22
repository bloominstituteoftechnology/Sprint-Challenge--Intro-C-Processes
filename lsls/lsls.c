#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
/**
 * Main
 */
int main(int argc, char **argv)
{
	int i;
	DIR *open;
	char *file_name;
	struct dirent *ent;

  // Parse command line
	printf("There are %d command line argument(s):\n", argc);

	for (i = 0; i < argc; i++) {
		printf("CL argument: %s\n", argv[i]);
	}

	// Open directory
	open = opendir(argv[1]);

	if (open == NULL) { // error check
		printf("Cannot open directory %s\n", argv[1]);
		exit(1);
	}

  // Repeatly read and print entries until end of directory stream  is reached
	while ((ent = readdir(open)) != NULL) { 
		printf("check: %s\n", ent->d_name);
		if (!strcmp(ent->d_name, ".") || !strcmp(ent->d_name, "..")) {
			// do nothing with . and .. entries
		} else {
			file_name = ent->d_name;
			printf("file_name: \"%s\"\n", file_name);
		}	
	}
  // Close directory
	closedir(open);
  return 0;
}