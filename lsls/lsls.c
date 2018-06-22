#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
    char* dirName = argv[1] == NULL ? "." : argv[1];
    struct dirent* ent;
    DIR* dirPointer;

    if (!(dirPointer = opendir(dirName))) {
        fprintf(stderr, "Error: Could not open directory %s\n", dirName);
        return -1;
    }

    while(ent = readdir(dirPointer)) {
        printf("%s\n", ent->d_name);
    }

    closedir(dirPointer);

  return 0;
}
