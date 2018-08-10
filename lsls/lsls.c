#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include<string.h>

#define DEFAULT_DIR "./"

int list_dir(char directory_path[]) {
  // Open directory
  DIR* opened_directory = opendir(directory_path);
  if (opened_directory != NULL) {
    struct dirent* entry;
    while((entry = readdir(opened_directory)) != NULL) {
      //filter out . and .. directories
      if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
        printf("%s\n", entry->d_name);
      }
    }
    // Close directory
    return closedir(opened_directory);
  } else {
    return EXIT_FAILURE;
  }
}

int main(int argc, char* argv[])
{
  // list directory for every passed in argument
  if (argc > 1) {
    for (int i = 1; i < argc; i++) {
      switch (list_dir(argv[i]))
      {
        case -1:
          printf("Failed to close directory %s\n", argv[i]);
          break;
        case 0:
          break;
        case 1:
          printf("Failed to open directory %s\n", argv[i]);
        default:
          break;
      }
    }
  } else {
    list_dir(DEFAULT_DIR);
  }
  return EXIT_SUCCESS;
}
