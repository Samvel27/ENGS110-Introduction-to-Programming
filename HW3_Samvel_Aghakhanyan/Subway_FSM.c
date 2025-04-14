#include <stdio.h>

// enum for states of the process
typedef enum {
	START,
	PAYMENT_REQUEST,
	PAYMENT_FAIL,
	PAYMENT_COMPLETED,
	END
} STATE;

int main() {
	STATE current_state = START; // setting the current state
	int inserted_money, number_of_tickets, change; // declaring variables

	while(current_state != END) { 
		switch (current_state) {
			case START: printf("Welcome to the subway!\nPlease complete the payment to buy a ticket.\n"); // User enters subway, greeting message
				    current_state = PAYMENT_REQUEST; // switch to next state where user should buy a ticket
				    break;
			case PAYMENT_REQUEST: printf("\nPlease insert money to buy a ticket.\nCost of one ticket is 150 AMD.\n"); // asking the user to buy a ticket
					      if (scanf("%d", &inserted_money) != 1) { // obtaining money input and checking validity
						      printf("\nError: Invalid input\n\n");
						      while (getchar() != '\n'); // clearing buffer
						      current_state = START; // changing state, returning to the beginning
						      break;
					      }
					      if (inserted_money < 150) { // checking if there is enough money for at least one ticket
						      current_state = PAYMENT_FAIL; // changing the state to failed
						      break;
					      }
					      printf("How many tickets you want to buy?\n"); // asking to know the number of tickets user wants to buy
                                              if ((scanf("%d", &number_of_tickets) != 1) || (number_of_tickets < 1)) { // obtaining number of tickets and checking validness of input
                                                      printf("\nError: Invalid input\n\n");
                                                      while (getchar() != '\n'); // clearing buffer
                                                      current_state = START; // changing state, returning to the beginning
                                                      break;
                                              }
                                              if ((number_of_tickets * 150) > inserted_money) { // if there is not enough money, state changes to failed
						      current_state = PAYMENT_FAIL;
                                                      break;
                                              }
					      current_state = PAYMENT_COMPLETED; // if everything is okay, changing state which indicates the payment is completed
					      break;
			case PAYMENT_FAIL: printf("\nPayment failed.\nNot enough money!\n\n"); // message in case payment failed
					   current_state = START; // changing state, returning to the beginning
					   break;
			case PAYMENT_COMPLETED: change = inserted_money - number_of_tickets * 150; // calculating the change
						number_of_tickets--; // employing one ticket for this ride
						if (number_of_tickets) printf("You still have %d tickets!\n", number_of_tickets); // outputting the number of tickets left
						if (change) printf("You inserted %d AMD more.\nPlease take your change!\n", change); // outputting the change
						current_state = END; // changing the state to the end
			case END: printf("\nGreat! The payment was successful!\nEnjoy your transfer.\n"); // process ends
				  break;
		}
	}

	return 0;
}
