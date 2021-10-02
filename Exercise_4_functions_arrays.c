/* 
   The intent of this program is to let the user input a string and then the user can choose one of three options. They can either
   receive the length of the string, the frequency of each letter case sensitive, or the frequency of each letter non-case
   sensitive. Lastly a 4th option is offered which safely exits the program.
 */
#include <stdio.h>                             		// This allows printf/scanf to be used
int enterString (char []);
int calcStrLength (char [], int);
int caseSensitiveSearch(char [], char [], int [],int );
int nonSensitiveSearch(char [],char [],char [], int []);
                                                	// Function prototypes
const int SIZE = 1000;
int main(){
    	char Uplets[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    	char Lowlets[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    	int letsvals[26] = {0};                     	// Integer array to values of non-case sensitive letters
    	char letters[] = {'A','a','B','b','C','c','D','d','E','e','F','f','G','g','H','h','I','i','J','j','K','k','L','l','M','m','N',
                          'n','O','o','P','p','Q','q','R','r','S','s','T','t','U','u','V','v','W','w','X','x','Y','y','Z','z'};
                                                	// Character array to store characters
    	int Lvalues[52] = {0};                      	// Integer array to store values of characters
    	static int counter = 0;
    	char userStr[SIZE];                         	// Character array to store user string
    	char userChoice;                            	// Variable reserved for the users input
    	int stringLength = 0, strLength = 0;        	// Variable reserved for the string length
    	do {
        	printf("1) Enter string\n");
        	printf("2) Calculate string lenth\n");
        	printf("3) Count characters (case sensitive)\n");
        	printf("4) Count characters (non-case sensitive)\n");
        	printf("5) Exit the program\n");
                                                	// Displaying the menu for the user
        	newLinefixer:
        	scanf("%c", &userChoice);               // Allowing for user input
        	switch (userChoice){
        		case '1':
            			printf("You chose to enter a string.\n");
                                                	// Informing the user option 1 was selected
            			enterString(userStr);
                                                	// Calling the function to allow the user to enter a string
            			break;                  // Returning back to the menu
        		case '2':
            			printf("You chose to calculate the length of the string.\n");
                                                	// Informing the user option 2 was selected
            			strLength = calcStrLength(userStr, stringLength);
            			printf("The length of the string is %d\n", strLength);
            			break;
        		case '3':
            			printf("You chose to analyze the string. (case sensitive)\n");
                                                	// Informing the user option 3 was selected
            			caseSensitiveSearch(userStr, letters, Lvalues, counter);
            			break;
        		case '4':
            			printf("You chose to analyze the string. (non-case sensitive)\n");
                                                	// Informing the user option 4 was selected
            			nonSensitiveSearch(userStr, Uplets, Lowlets, letsvals);
            			break;
        		case '5':
            			return 0;
        		case '\n':
            			goto newLinefixer;
                                                	// End of program
        		default:
            			printf("Please enter a valid menu option (1-5).\n");
                                                	// Prompting the user for valid input if incorrect number is input
            			break;
        	}

    	}
    	while(userChoice != 5);
}
 //**********************************************************
 //*This function is intended to allow the user to input a  *
 //*string that is then saved into a character array.       *
 //**********************************************************
 int enterString(char userStr[]){           		// Beginning of enterString function
    	char trash[SIZE];                       	// Array to clear the std stream
    	gets(trash);                            	// Clearing the std stream
    	printf("Enter a string: ");             	// Prompting the user for a string
    	gets(userStr);                          	// Allowing user to input string
    	printf("\nYou entered: %s\n", userStr); 	// Displaying string back to user
    	return;                                 	// Returning to menu
 }                                          		// End of enterString function
//***********************************************************
//*This function is intended to allow the user to know how  *
//*long a string is that they have input.                   *
//***********************************************************
int calcStrLength(char userStr[], int stringLength){
                                            		// Beginning of clacStrLength function
    	if (userStr[stringLength] == '\0'){
                                            		// Checking if the current character is the end of the string
        	return stringLength;
	}               				// If it is return current number value of size
    	else
        	stringLength++;                     	// If it isn't go to the next byte (character) and check that one
        return calcStrLength(userStr, stringLength);
                                            		// Recursively calling the function again on the next character
}                                           		// End of calcStrLength function
//***********************************************************
//*This function is intended to allow the user to determine *
//*how many occurrences of each character (upper and lower) *
//*occur.                                                   *
//***********************************************************
int caseSensitiveSearch(char userStr[], char letters[], int Lvalues[],int counter){
                                            		// Beginning of caseSensitiveSearch function
    	int charcounter = 0;
    	int i;                                  	// Index designated to cycle through 'ALPHA' arrays
        if (userStr[counter] != '\0'){      		// Cycling through the entire string
        	for (i = 0; i < 52; i++){           	// Cycling through the entire 'ALPHA' arrays
            		if (userStr[counter] == letters[i]){
                                            		// Checking if the letter in the string is a letter in the alphabet
                		Lvalues[i]++;           // If letters match the array holding the values for that character is incremented
            		}
        	}
        	counter++;                          	// Going to the next character in string
        	return caseSensitiveSearch(userStr, letters, Lvalues, counter);
                                            		// Recursively calling the function again on the next character
    	}
        printf("Character\t # of Occurrences\n");
                                            		// Printing the table header
    	for (i = 0; i < 52; i++){               	// Cycling through the 'ALPHA' arrays
        	if (Lvalues[i] != 0){               	// Checking if character was even in string
        		printf("  %c\t  %d \n", letters[i], Lvalues[i]);
                                            		// If character was in string character and # of occurrences printed
        		charcounter++;                  // Incrementing counter of # of characters used
        	}
    	}
        printf("Total:    %d\n", charcounter); 		// Displaying number of characters used
}                                           		// End of caseSensitiveSearch function
//***********************************************************
//*This function is intended to allow the user to determine *
//*how many occurrences of each character occur             *
//***********************************************************
int nonSensitiveSearch(char userStr[], char Uplets[],char Lowlets [], int letsvals[]){
                                            		// Beginning of nonSensitiveSearch function
    	int charcounter = 0;                    	// Counter for number of characters used
    	int counter = 0;                        	// Variable designated to keep track of the user string
    	int i, j = 0;                           	// Index designated to cycle through the 'ALPHA' arrays
    	while (userStr[counter] != '\0'){       	// Cycling through the entire string
        	for (i = 0; i < 26; i++){           	// Cycling through the entire 'ALPHA' arrays
            		if (userStr[counter] == Uplets[i]){
                                            		// Checking if letter in the string is a upper case letter
               			letsvals[i]++;          // If letters match the array holding the values for that character is incremented
            		}
            	}
        	for (i =0; i <26; i++){
            		if (userStr[counter] == Lowlets[i]){
                                            		// Checking if letter in the string is a lower case letter
               			letsvals[i]++;          // If letters match the array holding the values for that character is incremented
            		}
        	}

        counter++;                          		// going to the next character in string
    	}
      	printf("Character\t # of Occurrences\n");
                                            		// Printing the table header
    	for (i = 0; i < 26; i++){               	// Cycling through the 'ALPHA' arrays
        	if (letsvals[i] != 0){              	// Checking if character was even in string
        		printf("  %c\t  %d \n", Uplets[i], letsvals[i]);
                                            		// If character was in string character and # of occurrences printed
        		charcounter++;                  // Incrementing counter of number of characters used
        	}
    	}
        printf("Total:    %d\n", charcounter); 		// Displaying number of characters used
}                                           		// End of nonSensitiveSearch function
