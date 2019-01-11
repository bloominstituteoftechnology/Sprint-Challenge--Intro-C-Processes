#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define max_filepath_length 200
#define dir_string "<DIR>"

void print_sub_dir(char *filepath)
{
  // Open directory
  DIR *sub_dir = opendir(filepath);

  // Repeatly read and print entries
  struct dirent *sub_dir_entry;
  struct stat sub_buf;

  while ((sub_dir_entry = readdir(sub_dir)) != NULL) {
    char *sub_entry_name = sub_dir_entry->d_name;

    char sub_filepath[max_filepath_length] = "";
    strcpy(sub_filepath, filepath);
    strcat(sub_filepath, "/");
    strcat(sub_filepath, sub_entry_name);

    if (strlen(sub_filepath) > max_filepath_length) {
      fprintf(stderr, "Filepath too long: %s\n", sub_filepath);
      exit(1);
    }

    stat(sub_filepath, &sub_buf);

    if ((sub_buf.st_mode & S_IFDIR) != 0)
    {
      // a non-zero result is a directory
      printf("%17s %s\n", dir_string, sub_entry_name);
    }
    else
    {
      printf("%17ld %s\n", sub_buf.st_size, sub_entry_name);
    }
  }

  // Close directory
  closedir(sub_dir);
}


/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  if (argc < 2)
  {
    fprintf(stderr, "usage: lsls <dirname>\n");
    exit(1);
  }

  char *dirname = argv[1];

  // Open directory
  DIR *dir;
  if((dir = opendir(dirname)) == NULL)
  {
    char error_msg[] = "Cannot open directory ";
    strcat(error_msg, dirname);
    perror(error_msg);
    exit(1);
  }

  // Repeatly read and print entries
  struct dirent *dir_entry;
  struct stat buf;

  while ((dir_entry = readdir(dir)) != NULL) {
    char *entry_name = dir_entry->d_name;

    char filepath[max_filepath_length] = "";
    strcpy(filepath, dirname);
    strcat(filepath, "/");
    strcat(filepath, entry_name);

    if (strlen(filepath) > max_filepath_length) {
      fprintf(stderr, "Filepath too long: %s\n", filepath);
      exit(1);
    }

    stat(filepath, &buf);

    if ((buf.st_mode & S_IFDIR) != 0)
    {
      // a non-zero result is a directory
      printf("%10s %s\n", dir_string, entry_name);
      print_sub_dir(filepath);
    }
    else
    {
      printf("%10ld %s\n", buf.st_size, entry_name);
    }
  }

  // Close directory
  closedir(dir);

  return 0;
}
