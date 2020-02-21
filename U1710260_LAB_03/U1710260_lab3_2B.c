#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

/*LAB #3 - 2B*/

// Jamshidjon Khakimjonov // UnixProg // U1710260 //

void main(){
    int fd;
    char message[] = "I want 100 for this Lab";
    while((fd = open("grade.txt", O_WRONLY, 0777)) == -1){
        1;
    }
    write(fd, message, strlen(message));
}