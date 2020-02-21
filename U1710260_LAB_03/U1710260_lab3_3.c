#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

/*LAB #3 - 3*/

// Jamshidjon Khakimjonov // UnixProg // U1710260 //

double pow(double num, int pow) {
    double temp = num;
    for (int i = 1; i < pow; i++) { num *= temp; }
    return num;
}

int main(int n, char *args[]) {
    double x, result = 1;
    int m;
    x = atof(args[1]);
    n = atoi(args[2]);
    for(int i = 1; i <= m; i++){
        result += pow(x, i);
    }
    printf("1/(1-x)) = %f\n", result);
    return 0;
}

