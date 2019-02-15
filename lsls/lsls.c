#include <dirent.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
    
    char *currentDir;
    char *inputDir;
    struct dirent *entry;
    struct stat buf;
    
    currentDir = argv[0];
    
    if (argc >= 1) {
        // If number of arguments is higher then one, then take the first argument
        inputDir = argv[1];
    }
    
  // Open directory
    DIR *dir;
    
    //
    if (inputDir != NULL) {
        // Check specific directory
        dir = opendir(inputDir);
    } else {
        // Check current directory
        dir = opendir(".");
    }
    
    if (dir == NULL) {
        printf("Could not open directory %s\n", inputDir);
        return 0;
    }
    
    entry = readdir(dir);
    
    // Repeatly read and print entries
    while (entry != NULL) {
        // Get file size
        stat(entry->d_name, &buf);
        // Print size and name
        printf("%lld ", buf.st_size);
        printf("%s\n", entry->d_name);
        entry = readdir(dir);
    }
    
  // Close directory
    
    if (dir != NULL) {
        closedir(dir);
    }

  return 0;
}

