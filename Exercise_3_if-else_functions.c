/*   
        This program is designed to offer the user the choice of determining the accuracy of the
        power series expansions of the exponential function and the sinusoidal function
        juxtaposed with the values determined by the advanced C-math functions. The cherry on
        top is the program displays the comparison in tabular format to allow for easy reading.

 */
# include <stdio.h>
                                			// Preprocessor directive to allow printf/scanf to be utilized
# include <math.h>
                                			// Preprocessor directive to allow math functions to be used
int exponentialfunction (char);
int sinusoidalfunction (char);
double factorial (int);
                                			// Function prototypes
int main(){
                                			// Beginning of main function

    	char userChoice = 'a';
                                			// Character variable for user input
    	do {
    		printf("Please select an option: \n");
    		printf("   a) Evaluate exponential function\n");
    		printf("   b) Evaluate sinusoidal function\n");
    		printf("   c) Exit\n");
                                			// Displaying the menu for the user
    		garbagefixer:
    		scanf("%c", &userChoice);

                                			// Allowing for user input
    		switch(userChoice){
        		case 'A':
        		case 'a':{
            			exponentialfunction(userChoice);
            			break;              	// Exponential function call for when choice a is chosen
            		}
        		case 'B':
        		case 'b':{
            			sinusoidalfunction(userChoice);
            			break;              	// Sinusoidal function call for when choice b is chosen
            		}
        		case 'C':
        		case 'c':
        			return 0;
        		default:{
        			printf("Please enter choice a, b, or c.\n");
                                			// Error message for incorrect input
        			break;
        		}
        	}
    	}
    	while (userChoice != 'c' || 'C');
                                			// Displaying the menu for the user to select from
}
                                			// End of main
//**********************************************************************************
//*Exponential function: This function is intended to ask the user for a value to  *
//*evaluate then the number of terms to use in the evaluation using a power series *
//*expansion to estimate the value. The function then utilizes the MATH.H library  *
//*to evaluate the same value with C's exponential function. Lastly the two values *
//*are then compared and the percent error and both values are displayed in a      *
//*tabular format.                                                                 *
//**********************************************************************************
int exponentialfunction(char userChoice){
                                			// Beginning of exponential function
	double expValue, realValue, percentError, factValue = 1;
        float xValue, percError;
        int termsNum, counter;
                               				// Variable declarations for variables needed
   	printf("Please enter the x value to be evaluated: \n");
                                			// Prompting the user for the x-value
    	scanf("%f", &xValue);
                                			// Allowing for user input
    	printf("Please enter the number of terms for the power series to use: \n");
                                			// Prompting the user for the number of terms to
                                			// use in the power series expansion
    	scanf("%d", &termsNum);
                                			// Allowing for user input
    	if (termsNum == 1){
        	expValue = 1;
    	}
    	else if (termsNum == 2){
        	expValue = 1 + xValue;
    	}
                                			// In the case of 1 term no for loop or factorials
                                			// will be needed therefor requires its own case
    	else if (termsNum >=2){
                                			// In the case of 2 terms or more a loop will be
                                			// needed
        	expValue = 1 + xValue;
                                			// Accounting for first term
        	for (counter = 2; counter <= termsNum; counter++){
           		factValue = factorial(counter);
                                			// Function tall to evaluate factorial
            		expValue = expValue + (((pow(xValue,counter))/(factValue)));
        	}
                                			// A loop to calculate the exponential estimation
                                			// gathered from the power series
    	}
    	realValue = exp(xValue);
                                			// CMATH's exponential function evaluation
    	percError = fabs(((expValue - realValue)/realValue)*100);
                                			// Calculating the percent error
        printf("X-value\tTerms\tResult\t\tMATH.H\t\tPercent Error\n");
    	printf("%.1f\t  %d\t %7.4f\t  %7.4f\t%14.4f\n",xValue, termsNum, expValue, realValue, percError);
}
                                			// End of exponential function
//*********************************************************************************
//*Factorial function: this function is designed to receive a number that it then *
//*calculates the factorial of that number and returns it.                        *
//*********************************************************************************
double factorial(counter){
                                			// Beginning of factorial function
    	double factOut = 1;
	int i;
                                			// Variable declarations needed for function
	for (i = 1; i <= counter; i++){
		factOut *= i;
	}
                                			// For loop used to calculate factorial of integer
	return factOut;
                                			// Returning the value of the integer's factorial
}
                                			// End of factorial function
//*********************************************************************************
//*Sinusoidal function: This function is intended to ask the user for a value to  *
//*evaluate then the number of terms to use in the evaluation using a power series*
//*expansion to estimate the value. The function then utilizes the MATH.H library *
//*to evaluate the same value with C's sinusoidal function. Lastly the two values *
//*are then compared and the percent error and both values are displayed in a     *
//*tabular format.                                                                *
//*********************************************************************************
int sinusoidalfunction(char userChoice){
                                			// Beginning of sinusoidal function
    	double sinValue, realValue, factValue = 1;
    	float xValue, percError;
    	int termsNum, counter, counter2 = 1, counter3 = 1;
                                			// Variable declarations needed for function
    	printf("Please enter the x value to be evaluated: \n");
                                			// Prompting user for x-value
    	scanf("%f", &xValue);
                                			// Allowing for user input
    	printf("Please enter the number of terms for the power series to use: \n");
                                			// Prompting the user for the number of terms to
                                			// use in the power series expansion
    	scanf("%d", &termsNum);
                                			// Allowing for user input
    	if (termsNum < 2){
        	sinValue = xValue;
    	}
                                			// In the case of 1 term no for loop or factorials
                                			// are needed therefor it needs it's own case
    	else if (termsNum >= 2){
                                			// In the case of 2 terms or more a for loop will be
                               				// needed
        	sinValue = xValue;
                                			// Accounting for the first term
        	for (counter = 2, counter2 = 2, counter3 = 3; counter <= termsNum; counter++){
        		factValue = factorial(counter3);
            		if (counter2 % 2 == 0){
                		sinValue = sinValue + (((pow(xValue, counter3))/(factValue)))*-1;
            		}
            		else if (counter2 % 2 == 1){
                		sinValue = sinValue + (((pow(xValue, counter3))/(factValue)));
            		}
            		counter3 = counter3 + 2;
            		counter2 = counter2 +1;
        	}
	}
                                			// For loop used to calculate the sin value using the
                                			// power series expansion, since every other term is
                                			// negative the if else if statement checks which term
                                			// it is and applies negation as necessary
    	realValue = sin(xValue);
                                			// CMATH's sinusoidal evaluation
    	percError = fabs(((sinValue - realValue)/realValue)*100);
                                			// Calculating percent error
    	printf("X-value\tTerms\tResult\t\tMATH.H\t\tPercent Error\n");
    	printf("%.1f\t  %d\t %7.4f\t  %7.4f\t%14.4f\n",xValue, termsNum, sinValue, realValue, percError);


}
                                			// End of sinusoidal function