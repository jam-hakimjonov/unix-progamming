#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

/*LAB #3 - 2A*/

// Jamshidjon Khakimjonov // UnixProg // U1710260 //

void main() {
    int fd;
    char message[] = "I want 0 for this Lab";
    if ((fd = open("grade.txt", O_CREAT | O_EXCL | O_WRONLY, 0777)) == -1){
        write(fd, message, strlen(message));
    }
}