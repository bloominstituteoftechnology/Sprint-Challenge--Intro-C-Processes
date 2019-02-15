#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  // By default the current directory is represented by "."
  char *directoryToEnumerate = ".";
  
  // If the user specifies their own path, use it
  if (argc > 1) {
    directoryToEnumerate = argv[1];
  }

  // Open directory
  DIR *directoryEnumerator = opendir(directoryToEnumerate);
  
  if (directoryEnumerator == NULL) {
    perror("Error opening directory");
    exit(1);
  }
  
  // Get length of the directory
  // Better to do it here once than inside the while loop, even though we're using it in there
  // Because strlen() is O(n), and looping through O(n) is not good
  int directoryNameLength = strlen(directoryToEnumerate);

  // Repeatly read and print entries
  struct dirent *directoryEntry;
  
  while ((directoryEntry = readdir(directoryEnumerator))) {
    // Get the name of the directory entry
    char *fileName = directoryEntry->d_name;  // Use -> b/c directoryEntry is a pointer
    
    // Build up the path to get the file size
    // Get length of file name
    int fileNameLength = directoryEntry->d_namlen;
    
    // // directoryNameLength + "/" + fileNameLength + "\0"
    char *filePath = malloc((directoryNameLength + 1 + fileNameLength + 1)*sizeof(char));
    sprintf(filePath, "%s/%s", directoryToEnumerate, fileName);
    
    // Get file statistics
    struct stat fileStats;
    stat(filePath, &fileStats);
    long long fileSize = fileStats.st_size;
    
    // Stretch: Print <DIR> for directory
    switch (fileStats.st_mode & S_IFMT){
      case S_IFDIR:
        printf("     <DIR>  %s\n", fileName);
        break;
      default:
        printf("%10lld  %s\n", fileSize, fileName);
    }
    
//    printf("%10lld  %s\n", fileSize, fileName);
    
    free(filePath);
  }

  // Close directory
  closedir(directoryEnumerator);

  return 0;
}