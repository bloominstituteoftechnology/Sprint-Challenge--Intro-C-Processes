#include <stdio.h>
#include <dirent.h>

/**
 * Main
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    FILE* fp;
    fp = fopen("text.txt", "w");

    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("child process here\n");
        char child_str[] = "This is child string!\n";
        fwrite(child_str, 1, sizeof(child_str) - 1, fp);
    } else {
        printf("parent process here\n");
        char parent_str[] = "This is parent string!\n";
        fwrite(parent_str, 1, sizeof(parent_str) - 1, fp);
    }
    fclose(fp);
    return 0;
}