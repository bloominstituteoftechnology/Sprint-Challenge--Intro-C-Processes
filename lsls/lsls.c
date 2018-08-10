#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line


  char show_hidden = 0;

  char my_path_index = 0;

  char long_output = 0;



  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-') {
      int j = 1;
      while (argv[i][j] != '\0') {
        if (argv[i][j] == 'a') {
          show_hidden = 1;
        }
        else if (argv[i][j] == 'l') {
          long_output = 1;
        }
        j++;
      }
    }
    else {
      my_path_index = i;
    }

  }




  // Open directory

  DIR *directory;

  char my_path[sizeof(argv[my_path_index])];

  if (my_path_index) {
    strcpy(my_path, argv[my_path_index]);
  }
  else {
    strcpy(my_path, ".");
  }

  directory = opendir(my_path);




  // Repeatly read and print entries

  struct dirent *current_file;

  while ((current_file = readdir(directory)) != NULL) {
    if (show_hidden || current_file->d_name[0] != '.') {
      if (long_output) {
        char my_full_path[1024];
        strcpy(my_full_path, my_path);
        if (my_full_path[strlen(my_full_path) - 1] != '/') {
          strcat(my_full_path, "/");
        }
        strcat(my_full_path, current_file->d_name);

        struct stat file_stats;
        stat(my_full_path, &file_stats);
        if (S_ISDIR(file_stats.st_mode)) {
          printf("<DIR>\t");
        }
        else {
          printf("%ld\t", file_stats.st_size);
        }
      }
      printf("%s\n", current_file->d_name);
    }
  }

  // Close directory

  closedir (directory);

  return 0;
}