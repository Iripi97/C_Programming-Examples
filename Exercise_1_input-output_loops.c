/*      
            This program was designed to receive input from the user (a numeric value and a character) and then takes those
        values and prints them in a pyramid like pattern. The program contains little error checking due to the
        specificity of the prompts.

 */
#include <stdio.h>
                                		// Preprocessor directive to allow for printf/scanf to be utilized
int main(){
                                		// Beginning of main function
	int UserNum;
    	char UserChar;
                                		// Variable declarations for user input
    	int rows, k=0;
    	int extraCounter = 1;
                                		// Variables reserved for printing (loop variables)
    	do{
    		printf("Please enter a positive integer then a character (no spaces): ");
                                		// Prompting the user for input
    		scanf("%d", &UserNum);
                                		// Allowing the user to enter a digit
    		scanf("%c", &UserChar);
                                		// Allowing the user to enter a character
    	}
    	while (UserChar == '\n' || UserNum < 0 || UserChar == ' ');
                                		// While loop used to create parameters that if not filled will be repeated asked for
    	for (rows = 1; rows <=UserNum; ++rows, k=0){                       		
						// For loop designed to print the correct number of rows
        	for(extraCounter = 1; extraCounter <= UserNum-rows; ++extraCounter){                       		
						// For loop designed to print the correct spacing (columns as well)
            		printf(" ");
                                		// Printing the spacing
        	}
        	while (k != 2*rows-1){                   		
						// While loop designed to print the desired user inputed character
            		printf("%c", UserChar);
                                		// Printing the character
            		++k;
        	}
        printf("\n");
                                		// Printing new line to start next row
    	}
                                		// Returning 0 to show program success
    	return 0;
}	                           		// End of main function

