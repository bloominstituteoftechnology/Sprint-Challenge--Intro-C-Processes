#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  if (argc < 2) {
    argv[1] = ".";
  }
  // Open directory
  DIR *d;
  // DIR *d2;
  d = opendir(argv[1]);
  if (d == NULL) {
    printf("opendir() failed");
    exit(1);
  }
  // Repeatly read and print entries
  struct dirent *entry;
  // struct dirent *entry2;
  struct stat buf;
  // struct stat buf2;
  char path[512];
  // char path2[512];
  // int i = 0;
  while ((entry = readdir(d)) != NULL) {
    // entry = readdir(d);
    sprintf(path, "%s/%s", argv[1], entry->d_name);
    stat(path, &buf);
    if (buf.st_mode & S_IFDIR) {
      printf("<DIR> %s\n", entry->d_name);
      // d2 = opendir(path);
      // if (i != 0 && i != 1) {
      //   while (entry2 != NULL) {
      //     entry2 = readdir(d2);
      //     sprintf(path2, "%s/%s", path, entry2->d_name);
      //     stat(path2, &buf2);
      //     if (buf2.st_mode & S_IFDIR) {
      //       printf("    <DIR> %s \n", entry2->d_name);
      //     } else {
      //       printf("    %ld %s \n", buf2.st_size, entry2->d_name);
      //     }
      //   }
      // }
      // i++;
    } else {
      printf("%o%ld %s \n",buf.st_mode, buf.st_size, entry->d_name);
    }
  }
  // Close directory
  closedir(d);
  return 0;
}