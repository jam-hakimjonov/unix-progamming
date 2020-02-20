#include <stdio.h>
#include <math.h>
#include <stdlib.h> // ATOI
#include <unistd.h> // WRITE/READ FUNCTIONS
# include <string.h> // for memcpy declaration
/*LAB #1 - 4*/

// Jamshidjon Khakimjonov // UnixProg // U1710260 //

int factorial(int input) {
	if (input>=1)
		return input*(factorial(input-1));
	return 1;
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
                sprintf(buffer, "%d", factorial(input)); 
				write(1, output_label, sizeof(output_label));
				write(1, buffer, sizeof(int));
				printf("\nPress enter to continue or 'q' to quit: ");
				fflush(stdin);
				quit = getchar();
		}
	return 0;
}
