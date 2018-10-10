#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

/**
 * Displays filename details
 */
void displaydetails(char *filename) {
  struct stat st;
  stat(filename, &st);
  mode_t smode = st.st_mode;
  size_t filesize = st.st_size;
  char dir_msg[] = "<DIR>";

  if ((smode & S_IFMT) == S_IFDIR) {
    printf("%10s %s\n", dir_msg, filename);
  } else if ((smode & S_IFMT) == S_IFREG) {
    printf("%10zu %s\n", filesize, filename);
  }
}

/**
 * Displays error message
 */
void displayerror(char *workingdir) {
  char error_message[] = "🙅‍ Cannot open ";
  const size_t len1 = strlen(error_message);
  const size_t len2 = strlen(workingdir);
  char *result = malloc(len1 + len2 + 1);
  strcpy(result, error_message);
  strcat(result, workingdir);
  perror(result);
  free(result);
  exit(1);
}

/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *dir;
  struct dirent *dp;
  char *workingdir;

  // Change directory if commandline args are supplied
  if (argc > 1) {
    workingdir = argv[1];
    chdir(workingdir);
  } else {
    workingdir = ".";
  }

  // Open directory. If unable to, display an error message
  if ((dir = opendir(workingdir)) == NULL) {
    displayerror(workingdir);
  }

  // Read directory stream until NULL. printf details
  while ((dp = readdir(dir)) != NULL) {
    char *filename = dp->d_name;
    displaydetails(filename);
  }

  // Close directory
  closedir(dir);

  return 0;
}