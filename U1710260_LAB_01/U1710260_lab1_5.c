#include <stdio.h>
#include <math.h>
#include <stdlib.h> // ATOI
#include <unistd.h> // WRITE/READ FUNCTIONS
/*LAB #1 - 5*/

// Jamshidjon Khakimjonov // UnixProg // U1710260 //

int main() {
		char quit;
		char buffer[1024];
		char *input_label = "Base: ";
		char *output_label = "Result: ";
		while(quit != 'q') {
				write(1, input_label, sizeof(input_label)-1);
				double base, power;
				read(0, buffer, sizeof(double));
                base = atoi(buffer);
				input_label = "Power: ";
				write(1, input_label, sizeof(input_label));
                read(0, buffer, sizeof(double));
                power = atoi(buffer);
				sprintf(buffer, "%.2lf", pow(base, power));
				write(1, output_label, sizeof(output_label));
				write(1, buffer, sizeof(double));
				printf("\nPress enter to continue or 'q' to quit: ");
				fflush(stdin);
				quit = getchar();
		}
	return 0;
}
