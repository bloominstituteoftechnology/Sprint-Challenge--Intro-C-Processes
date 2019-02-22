#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

struct dirent *pDirent;
struct stat buf;
DIR *pDir;

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  if (argc < 2) {
    // Open directory
    pDir = opendir(".");
  } else {
    // Open directory
    pDir = opendir(argv[1]);
  }

  // Repeatly read and print entries
  while((pDirent = readdir(pDir)) != NULL) {
    stat(pDirent->d_name, &buf);

    // If the entry is a directory, ignore the size and label it <dir>
    if(S_ISDIR(buf.st_mode)) {

      printf("%s\t<DIR>\n", pDirent->d_name);

    } else {
      // Otherwise, print the name of the file and the file size
      printf("%s\t%10ld\n", pDirent->d_name, buf.st_size);

    }
  }
  // Close directory
  closedir(pDir);

  return 0;
}