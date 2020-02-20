#include <stdio.h>
#include <math.h>
#include <stdlib.h> // ATOI
#include <unistd.h> // WRITE/READ FUNCTIONS

/*LAB #1 - 1*/

// Jamshidjon Khakimjonov // UnixProg // U1710260 //

int isPrime(int input) {
	if (input <= 1)
		return 0;
	int i;
	for (i = 2; i<= input/2; i++)
		if(input % i == 0)
			return 0;
	return 1;
}

int main() {
		char quit;
		char buffer[1024];
		char *input_label = "Input: ";
		char *output_label = "Is prime: ";
		while(quit != 'q') {
				write(1, input_label, sizeof(input_label));
				int input;
				read(0, buffer, sizeof(int));
				input = atoi(buffer);
				write(1, output_label, sizeof(output_label)+2);
				write(1, (isPrime(input) ? "true" : "false"), 5);
				printf("\nPress enter to continue or 'q' to quit: ");
				fflush(stdin);
				quit = getchar();
		}
	return 0;
}
