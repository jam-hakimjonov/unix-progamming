#include <stdio.h>
#include <math.h>
#include <stdlib.h> // ATOI
#include <unistd.h> // WRITE/READ FUNCTIONS
# include <string.h> // for memcpy declaration
/*LAB #1 - 3*/

// Jamshidjon Khakimjonov // UnixProg // U1710260 //

int isOdd(int input) {
	if(input%2!=0)
		return 1;
	return 0;
}
int main() {
		char quit;
		char buffer[1024];
		char *input_label = "Input: ";
		char *output_label = "Result: ";
		while(quit != 'q') {
				write(1, input_label, sizeof(input_label));
				int input;
				read(0, buffer, sizeof(int));
                input = atoi(buffer);
                write(1, isOdd(input) ? "odd" : "even", sizeof(4));
				printf("\nPress enter to continue or 'q' to quit: ");
				fflush(stdin);
				quit = getchar();
		}
	return 0;
}
