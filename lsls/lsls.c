#include <stdio.h>
#include <dirent.h> // This header file holds the declarations for DIR, struct dirent, opendir(), readdir(), and closedir().

// ----------------opendir() ---------------- (http://man7.org/linux/man-pages/man3/opendir.3.html)
// SYNOPSIS         
//        #include <sys/types.h>
//        #include <dirent.h>

//        DIR *opendir(const char *name);
//        DIR *fdopendir(int fd);

//    Feature Test Macro Requirements for glibc (see feature_test_macros(7)):

//        fdopendir():
//            Since glibc 2.10:
//                _POSIX_C_SOURCE >= 200809L
//            Before glibc 2.10:
//                _GNU_SOURCE
// DESCRIPTION         
//        The opendir() function opens a directory stream corresponding to the
//        directory name, and returns a pointer to the directory stream.  The
//        stream is positioned at the first entry in the directory.

//        The fdopendir() function is like opendir(), but returns a directory
//        stream for the directory referred to by the open file descriptor fd.
//        After a successful call to fdopendir(), fd is used internally by the
//        implementation, and should not otherwise be used by the application.
// RETURN VALUE         
//        The opendir() and fdopendir() functions return a pointer to the
//        directory stream.  On error, NULL is returned, and errno is set
//        appropriately.

// ----------------readdir()---------------- (http://man7.org/linux/man-pages/man3/readdir.3.html)
// SYNOPSIS        
//        #include <dirent.h>

//        struct dirent *readdir(DIR *dirp);
// DESCRIPTION         
//        The readdir() function returns a pointer to a dirent structure
//        representing the next directory entry in the directory stream pointed
//        to by dirp.  It returns NULL on reaching the end of the directory
//        stream or if an error occurred.

//        In the glibc implementation, the dirent structure is defined as
//        follows:

//            struct dirent {
//                ino_t          d_ino;       /* Inode number */
//                off_t          d_off;       /* Not an offset; see below */
//                unsigned short d_reclen;    /* Length of this record */
//                unsigned char  d_type;      /* Type of file; not supported
//                                               by all filesystem types */
//                char           d_name[256]; /* Null-terminated filename */
//            };

//        The only fields in the dirent structure that are mandated by POSIX.1
//        are d_name and d_ino.  The other fields are unstandardized, and not
//        present on all systems; see NOTES below for some further details.

// RETURN VALUE         
//        On success, readdir() returns a pointer to a dirent structure.  (This
//        structure may be statically allocated; do not attempt to free(3) it.)

//        If the end of the directory stream is reached, NULL is returned and
//        errno is not changed.  If an error occurs, NULL is returned and errno
//        is set appropriately.  To distinguish end of stream and from an
//        error, set errno to zero before calling readdir() and then check the
//        value of errno if NULL is returned.

// ------------------closedir()------------- (http://man7.org/linux/man-pages/man3/closedir.3.html)
// SYNOPSIS         
//        #include <sys/types.h>

//        #include <dirent.h>

//        int closedir(DIR *dirp);
// DESCRIPTION         
//        The closedir() function closes the directory stream associated with
//        dirp.  A successful call to closedir() also closes the underlying
//        file descriptor associated with dirp.  The directory stream
//        descriptor dirp is not available after this call.
// RETURN VALUE         
//        The closedir() function returns 0 on success.  On error, -1 is
//        returned, and errno is set appropriately.


#include <sys/stat.h> // (http://man7.org/linux/man-pages/man2/fstat.2.html)
#include <string.h>
/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line

  // Open directory

  // Repeatly read and print entries

  // Close directory

  DIR *d;
  struct dirent *dir;
  struct stat statbuf;
  char *slash = "/";
  int exists;
  int total_size = 0;
  
  d = opendir(argv[1]);
  if (d) {
    while ((dir = readdir(d)) != NULL) {
      char fullpath[512];
      strcpy(fullpath,argv[1]);
      strcat(fullpath,slash);
      strcat(fullpath,dir->d_name);
      
      printf("fullpath: %s\n", fullpath);

      // printf("stat(fullpath, &statbuf) = %d\n", stat(fullpath, &statbuf));
      stat(fullpath, &statbuf);

      printf("%10lld kb  ", statbuf.st_size/1000);
      printf("%s\n", dir->d_name);

    }
    closedir(d);
  }
  
  // if (d) {
  //   for (dir = readdir(d); dir !=NULL; dir = readdir(d)) {
  //     char fullpath[512];
  //     strcpy(fullpath,argv[1]);
  //     strcat(fullpath,slash);
  //     strcat(fullpath,dir->d_name);
  //     exists = stat(fullpath, &statbuf);
  //     if (exists < 0) {
  //       fprintf(stderr, "Couldn't stat %s\n", dir->d_name);
  //     } else {
  //       total_size += statbuf.st_size;
  //     }
  //   }
  //   closedir(d);
  //   printf("%d\n", total_size);
  // }

  return 0;
}

