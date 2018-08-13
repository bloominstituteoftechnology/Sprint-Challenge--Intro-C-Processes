#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char *dir = ".";
  if (argc > 1) {
      dir = argv[1];
  }

  // Open directory
  DIR *dir_pointer = opendir(dir);

  if (dir_pointer == NULL) {
      printf("Could not open specified directory");
      exit(1);
  }

  // Repeatly read and print entries
  struct dirent *dir_entry;
  while ((dir_entry = readdir(dir_pointer)) != NULL) {
      struct stat buf;
      char file_path[1024];
      strcpy(file_path, dir);
      strcat(file_path, "/");
      strcat(file_path, dir_entry->d_name);
      stat(file_path, &buf);
      if (buf.st_mode & S_IFDIR) {
          printf("<DIR> %s\n", dir_entry->d_name);
      }
      else if (buf.st_mode & S_IFREG) {
          printf("%lld %s\n", buf.st_size, dir_entry->d_name);
      }
  }

  // Close directory
  closedir(dir_pointer);

  return 0;
}