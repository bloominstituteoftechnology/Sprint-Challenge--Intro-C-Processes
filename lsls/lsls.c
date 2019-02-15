#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

/**
 * Main
 */

void list_dir(char *dir)
{
    DIR *o_dir = opendir(dir);
    struct dirent *c_dir;
    struct stat buf;

    if (o_dir)
    {
        while ((c_dir = readdir(o_dir)) != NULL)
        {
            if (c_dir->d_type == 4) 
            {
                printf("(DIR) - %s\n", c_dir->d_name);
            } 
            else if (c_dir->d_type == 8) 
            {
                chdir(dir);
                stat(c_dir->d_name, &buf);
                printf("(%ld) - %s\n", buf.st_size, c_dir->d_name);
            }
        }
    }

    closedir(o_dir);
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        list_dir(("%s", argv[1]));
    }
    else if (argc != 2)
    {
        list_dir(".");
    }
    
    return 0;
}