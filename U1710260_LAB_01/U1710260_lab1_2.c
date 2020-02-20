#include <stdio.h>
#include <math.h>
#include <stdlib.h> // ATOI
#include <unistd.h> // WRITE/READ FUNCTIONS
# include <string.h> // for memcpy declaration
/*LAB #1 - 2*/

// Jamshidjon Khakimjonov // UnixProg // U1710260 //

double largest_finder(double a, double b, double c) {
	if (a >= b) {
		if (a >= c) 
			return a;
		else 
			return c;
	} else {
		if (b >= c)
			return b;
		else
			return c;
	}
	return 0; 
}

int main() {
		char quit;
		char buffer[1024];
		char *input_label = "Input: \n";
		char *output_label = "Result: ";
		while(quit != 'q') {
				write(1, input_label, sizeof(input_label));
				double a,b,c;
				read(0, buffer, sizeof(double));
				a = atoi(buffer);
                read(0, buffer, sizeof(double));
				b = atoi(buffer);
                read(0, buffer, sizeof(double));
				c = atoi(buffer);
				write(1, output_label, sizeof(output_label));
                sprintf(buffer, "%.2f", largest_finder(a,b,c)); 
				write(1, buffer, sizeof(double));
				printf("\nPress enter to continue or 'q' to quit: ");
				fflush(stdin);
				quit = getchar();
		}
	return 0;
}
