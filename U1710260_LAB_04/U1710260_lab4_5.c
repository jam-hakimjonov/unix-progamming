#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <time.h>

/*LAB #4 - 2*/

// Jamshidjon Khakimjonov // UnixProg // U1710260 //

int main(int n, char *args[]) {
    DIR *directory;
    struct dirent *file;
    struct stat buffer;
    time_t raw_time;
    struct tm *time_info;
    time(&raw_time);
    time_info = localtime(&raw_time);
    directory = opendir("./"); // for current directory 
    
    if(directory){
        printf("CURRENT LOCAL TIME AND DATE in UNIX EPOCH (SECONDS SINCE 1970.01.01 00:00): %ld", time(time_info));
        while(file = readdir(directory) != NULL){
            lstat(file->d_name, &buffer);
            if(S_ISREG(buffer.st_mode)){
                if(buffer.st_nlink>2){
                    printf("%s \n", file->d_name);
                }
            }
        }
        closedir(directory);
    }
    exit(0);
}