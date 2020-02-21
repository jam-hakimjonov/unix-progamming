#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

/*LAB #3 - 1*/

// Jamshidjon Khakimjonov // UnixProg // U1710260 //

int main(int n, char *args[]) {
    struct stat file;
    char linke_name[1024];
    int code;
    fprintf(stderr, "%s", args[1]);
    code = lstat(args[1], &file);
    if (code < 0) {
        printf("File does not exist");
        return 0;
    }
    if (S_ISLNK(file.st_mode))
        printf("It is a soft Link\n");
    else {
        printf("Size of file:%ld\nOwner id: %u\n", file.st_size, file.st_uid);
        sprintf(linke_name, "%sLink", args[1]);
        symlink(args[1], linke_name);
        printf("Link file: %s", linke_name);
    }
    return 0;
}