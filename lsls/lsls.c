#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
int main(int argc, char **argv) {

    struct dirent* dir_entry;
    char* directoryName;

    if (argc == 1) {
        directoryName = ".";
    }
    else if (argc == 2) {
        directoryName = argv[1];
    }
    else {
        fprintf(stderr, "Usages: ./lsls [directoryName]\n");
    }


    DIR *dir = opendir(directoryName);

    if (dir == NULL) {

        puts("Cannot open current directory");
        return 0;
    }

    while ((dir_entry = readdir(dir)) != NULL) {
        printf("%s\n", dir_entry->d_name);
    }

    closedir(dir);

    return 0;
}