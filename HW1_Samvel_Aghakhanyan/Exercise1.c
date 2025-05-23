#include <stdio.h>

int main() {
    	double num1, num2, result; // initializing variables for number 1, number 2 and result
    	char op; // initializing a char variable for operator
    	while (1) {
    		printf("Please input the arithmetic expression in the following form: number operation number\n(Enter 'q' to leave)\n\n");
    		if (scanf("%lf %c %lf", &num1, &op, &num2) != 3) { // obtaining the num1, num2 and operator while also checking if they are in correct data types
		        if (getchar() == 'q') break; // if user inputs q the program ends
        		printf("\nError: invalid expression\n\n"); // if not, it results in error
        		while (getchar() != '\n'); // clearing input buffer
        		continue;
		}
    		if (op == '+') result = num1 + num2; // addition
    		else if (op == '-') result = num1 - num2; // subtraction
    		else if (op == '*') result = num1 * num2; // multiplication
    		else if (op == '/') { // division
			if (num2 == 0) { // special case for divisor being 0
            			printf("\nError: Can't divide by 0\n\n");
            			continue;
        		} 
        		result = num1 / num2;
        	}
		else {
			printf("\nError: Unknown operation\n\n"); // for all other characters
			continue;
		}
        	printf("\n%lf %c %lf = %lf\n\n", num1, op, num2, result); // printing the result
        }
	return 0;
}
