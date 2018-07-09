#include <stdio.h>
#include <dirent.h>
#include <errno.h>

#define OUTPUT_BUFSIZE 1024

/**
 * Main
 */
int main(int argc, char **argv)
{
	// Parse command line
	if(argc != 2) {
		printf("Usage: %s <directory>\n", argv[0]);
		return 0;
	}

	DIR *dp;
	int status;
	struct dirent *direntp;

	// Open directory
	dp = opendir(argv[1]);
	if (dp == NULL) {
		perror("opendir");
		return 1;
	}

	// Repeatly read and print entries
	while ((direntp = readdir(dp)) != NULL) {
		printf ("%s\n", direntp->d_name);
	}

	// Close directory
	status = closedir(dp);
	if (status == -1) {
		perror("closedir");
		return 1;
	}

  return 0;
}
