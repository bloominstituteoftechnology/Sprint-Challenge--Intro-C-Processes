#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
	// Parse command line
	struct dirent *ent;
	struct stat buf;
	DIR *dir;
	int i;

    for (i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }

 	// Open directory

    if (argv[1] == NULL) {
    	dir = opendir(".");
    } else {
    	dir = opendir(argv[1]);
    }

    if (dir == NULL) {
    	printf("Error: Unable to open directory.\n");
    	exit(1);
    } 

	while ((ent = readdir(dir)) != NULL) {
		stat(ent->d_name, &buf);
		printf("%lld\t %s\n", buf.st_size, ent->d_name);
	}

    // Close directory
	closedir(dir);
	return 0;
}