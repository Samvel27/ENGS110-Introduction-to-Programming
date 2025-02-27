#include <stdio.h>
#include <math.h>

int main() {
   
    	/*If something is unclear in the code please email me, I will be happy to explain the code an the logic*/
   
    	int decimal = 0;
	int neg = 0; // initializing decimal and flag for indicating negative numbers
    	char binary[32] = {'0'}; // string for binary initially set to 0
    	printf("Please input a number in binary: (input all 32 bits)\n");
    	scanf("%s", binary); // obtaining binary
 
    	for (int i = 0; i < 32; i++) {
        	if (binary[i] != '0' && binary[i] != '1') { /* checking if the binary is inputted correct without any symbols other than 1 and 0*/
          		printf("\nError: Invalid input\n");
          		return 0;
        	}
    	}
   
    	if (binary[0] == '1') { /* if binary[0] is 1, means number is negative, so I first subtract 1, then find complement and calculate as if it is positive, then I will add minus sign*/
        	neg++; // indicating the number is negative
        	for (int i = 31; i >= 0; i--) { // subtracting 1
            		if (binary[i] == '1') { // finding where the first (from the right side) 1 is
                		binary [i] = '0'; // putting it 0
                		for (int j = i + 1; j <= 31; j++) { // for all the zeros from that first 1 up to the end putting 1
                    			binary[j] = '1';
                		}
			}
                	break;
            	}
        	for (int i = 0; i < 32; i++) { // complementing the number (1 will become 0, 0 will become 1)
            		if (binary[i] == '0') binary[i] = '1';
            		else binary[i] = '0';
		}
    	}
   
    	for (int i = 0; i < 32; i++) {
        	if (binary[i] == '1') decimal += (1 << (31 - i)); // for each 1 in the binary we add 2 in power of i to the decimal
    	}
   
    	if (neg) decimal = -decimal; // if number was negative we put the minus sign
   
    	printf("\nIts decimal representation is %d", decimal); // printing decimal
    	printf("\n");
	return 0;
}
