#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include<string.h>

#define DEFAULT_DIR "./"
#define OPEN_FAILURE_CODE 1
#define OPEN_FAILURE_MSG "Failed to open directory %s\n"
#define CLOSE_FAILURE_CODE -1
#define CLOSE_FAILURE_MSG "Failed to close directory %s\n"
#define LIST_DIR_SUCCESS_CODE 0
#define LIST_DIR_SUCCESS_MSG ""

int list_dir(char directory_path[]) {
  // Open directory
  DIR* opened_directory = opendir(directory_path);
  if (opened_directory != NULL) {
    struct dirent* entry;
    while((entry = readdir(opened_directory)) != NULL) {
      printf("%s\n", entry->d_name);
    }
    // Close directory
    return closedir(opened_directory);
  } else {
    return OPEN_FAILURE_CODE;
  }
}

void log_failure(int result_code, char directory_path[]) {
  switch (result_code)
  {
    case CLOSE_FAILURE_CODE:
      printf(CLOSE_FAILURE_MSG, directory_path);
      break;
    case LIST_DIR_SUCCESS_CODE:
      printf(LIST_DIR_SUCCESS_MSG, directory_path);
      break;
    case OPEN_FAILURE_CODE:
      printf(OPEN_FAILURE_MSG, directory_path);
  }
}

int main(int argc, char* argv[])
{
  // list directory for every passed in argument
  if (argc > 1) {
    for (int i = 1; i < argc; i++) {
      log_failure(list_dir(argv[i]), argv[i]);
    }
  } else {
    log_failure(list_dir(DEFAULT_DIR), DEFAULT_DIR);
  }
  return EXIT_SUCCESS;
}
