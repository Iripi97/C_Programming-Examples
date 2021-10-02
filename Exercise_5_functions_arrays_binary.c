/*
   This program is designed to allow the user to enter a  string and then determine if that string is a valid binary number.
   The user can then leave the program or calculate the value of that binary number.
 */
#include <stdio.h>                             				// Allows scanf/printf to be used
#include <math.h>
void isBinary(char []);
void decimalValue(char [], int);
                                                			// Function prototypes
const int SIZE = 1000;                         				// Constant to ensure user does not exceed array
int main(){                                    				// Beginning of main function
    	char userStr[SIZE];                         			// UserStr array initialization
    	char userChoice;                            			// Variable for user choice
    	printf("Enter a binary number: \n");        			// Prompting the user for binary number
    	gets(userStr);                              			// Allowing for user input
    	isBinary(userStr);                          			// Sending the number (String) to the isBinary function
    	return 0;                                   			// Returning 0 at possible end of program
}                                           				// End of main
//************************************************
//*This function is intended to receive a string *
//*by the user and then determine if that string *
//*is representative of a binary number.         *
//************************************************
void isBinary(char userStr[]){                 				// Beginning of isBinary function
    	int counter = 0;                            			// Counter variable to cycle through string
    	int sum = 0;                                			// Variable to store binary numbers decimal value
    	char userChoice;                            			// Variable for user choice
    	int stringCounter = 0;                      			// Variable to keep track of characters in string
    	int binaryCounter = 0;                      			// Variable to keep track of 0's and 1's
    	int stringStatus = 0;                       			// Variable to represent boolean status of binary number
    	while (userStr[counter] != '\0'){           			// Cycling through the string
        	if (userStr[counter] == '0' || userStr[counter] == '1'){
                                                			// Checking if the character is a 1 or 0
            		stringCounter++;                		// If it is a 1 or 0 both counters incremented
            		binaryCounter++;
        	}
        	else                                    		// If not only one counter is incremented (the character counter)
        		stringCounter++;
        		counter++;                     			// Going to next character in string
    	}
    	if (stringCounter == binaryCounter){        			// If counters match the string is a binary number
        	stringStatus = 1;                       		// Return "boolean" true
    	}
    	else                                        			// If counter dont match it isnt a binary number
        	stringStatus = 0;                       		// Return "boolean" false
    	switch(stringStatus){
    		case 1:                                 		// If true the user is prompted if they want the decimal value
    			printf("You entered: %s\n", userStr);       	// Showing the user what they entered
    			printf("Do you want to know the decimal value?(y/n)");
    			scanf("%c", &userChoice);                   	// Allowing the user to choose
    			switch (userChoice){                        	// If user wants decimal value the string is sent to dcimalValue function
    				case 'y':
    				case 'Y':
        				decimalValue(userStr, sum);
    				case 'n':
    				case 'N':
        				break;                         	// If no the program ends
    				case ' ':
    				case '\n':
        			break;
    			}
    			break;
    		case 0:                                     		// If false the user is told why the program just ends
    			printf("You did not enter a binary number (0's and 1's only)\n");

    			return;
    	}
    	return;
}                                              				// End of isBinary function
 //***********************************************
 //*This function is intended to receive a binary*
 //*number and then calculate its decimal value. *
 //***********************************************
void decimalValue(char userStr[], int sum){    				// Beginning of decimalValue function
    	int i = 0;                                  			// Second index
    	int stringCounter = 0;                      			// First index
    	while (userStr[stringCounter] != '\0'){     			// Cycling through string
        	stringCounter++;                        		// Counting number of bytes
    	}
    	while (stringCounter >= 0){                 			// Cycling backwards through string
            	if (userStr[stringCounter] == '0'){
                	;                               		// If 0 no value in binary
            	}
            	else if (userStr[stringCounter] == '1'){
                	sum = sum + 1*pow(2,i);         		// If 1 the binary place (decimal place) is calculated
            	}
        	stringCounter--;                        		// Decrementing counter back
        	i++;                                    		// Incrementing second index
    	}
    	printf("The decimal value is %d\n", sum/2); 			// Displaying decimal value to user
}                                          				// End of decimalValue function

