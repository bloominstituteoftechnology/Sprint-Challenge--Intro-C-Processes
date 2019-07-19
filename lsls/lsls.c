#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>

/**
 * Main
 */
char *concat(const char *s1, const char *s2)
{
  char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
  // in real code you would check for errors in malloc here
  strcpy(result, s1);
  strcat(result, s2);
  return result;
}

int main(int argc, char **argv)
{
	// Parse command line
	struct dirent *ent;
	struct stat buf;
	DIR *dir;
	int i;
	char *file_name;

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

		if (argv[1] != NULL) {
			file_name = concat(argv[1], ent->d_name);
			stat(file_name, &buf);
		} else {
			stat(ent->d_name, &buf);
		}

		printf("%lld\t %s\n", buf.st_size, ent->d_name);
	}

    // Close directory
	closedir(dir);
	return 0;
}