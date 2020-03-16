#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>

/*LAB #4 - 2*/

// Jamshidjon Khakimjonov // UnixProg // U1710260 //

int main(int n, char *args[]) {
    DIR *directory;
    struct dirent *file;
    struct stat buffer;
    directory = opendir("./"); // for current root directory 
    if(directory){
        printf("LIST OF FILES WITH WRITE PERMISSION ONLY [FOR CURRENT USER]:\n");
        while(file = readdir(directory) != NULL){
            lstat(file->d_name, &buffer);
            if(S_ISREG(buffer.st_mode) && buffer.st_mode & S_IWUSR){
                printf("%s\n", file->d_name);
            }
        }
        closedir(directory);
    }
    exit(0);
}