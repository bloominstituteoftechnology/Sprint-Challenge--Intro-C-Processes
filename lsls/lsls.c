#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
    char* dirName = argv[1] == NULL ? "." : argv[1];
    struct dirent* ent;
    DIR* dirPointer;
    struct stat statBuffer;

    if (!(dirPointer = opendir(dirName))) {
        fprintf(stderr, "Error: Could not open directory %s\n", dirName);
        return -1;
    }

    while(ent = readdir(dirPointer)) {
        stat(ent->d_name, &statBuffer);
        printf("%10lld %s\n", statBuffer.st_size, ent->d_name);
    }

    closedir(dirPointer);

  return 0;
}
