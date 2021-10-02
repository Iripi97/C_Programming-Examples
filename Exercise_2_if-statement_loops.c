/*     
            This program was designed to receive input from the user (numeric values) and then takes those
        values and creates a function of nth order (user dictated) and then evaluates that function on an
        interval and displays the data in a table. The program contains little error checking due to the specificity of the
        prompts.

 */
#include <stdio.h>
                                		// Preprocessor directive to allow for printf/scanf to be utilized
#include <math.h>
int main(){
                                		// Beginning of main function
    	int functionOrder = 0;
    	int coA = 0, coB = 0, coC = 0, coD = 0, coE = 0, coF = 0, i;
    	static float Xmin = 0, Xmax = 0;
    	float x = 0;
    	float fx = 0;
    	float maxCount;
    	double dx = 0;
                                		// Variable declarations/ initializations
    	do {
        	printf("Enter the order of the funtion (must be between [1,5]): ");
                                		// Prompting the user for the functions order
        	scanf("%d", &functionOrder);
                                		// Allowing for the user to input the order
    	}
    	while (functionOrder > 5 || functionOrder < 1);
                                		// Error checking that the order is within the bounds set by instructor
    	if (functionOrder == 5){                       		
						// Checking if the oder is 5
        	printf("Following the model: aX^5 + bX^4 + cX^3 + dX^2 + eX + f\n");
        	printf("Enter the value for coefficient a: ");
        	scanf("%d", &coA);
        	printf("Enter the value for coefficient b: ");
        	scanf("%d", &coB);
        	printf("Enter the value for coefficient c: ");
        	scanf("%d", &coC);
        	printf("Enter the value for coefficient d: ");
        	scanf("%d", &coD);
        	printf("Enter the value for coefficient e: ");
        	scanf("%d", &coE);
        	printf("Enter the value for coefficient f: ");
        	scanf("%d", &coF);
                                		// Giving the user the model of the equation with the order entered, and then prompting
                                		// the user for a value of each coefficient
    	}
     	if (functionOrder == 4){                       		
						// Checking if the order is 4
        	printf("Following the model: bX^4 + cX^3 + dX^2 + eX + f\n");
        	printf("Enter the value for coefficient b: ");
        	scanf("%d", &coB);
        	printf("Enter the value for coefficient c: ");
        	scanf("%d", &coC);
        	printf("Enter the value for coefficient d: ");
        	scanf("%d", &coD);
        	printf("Enter the value for coefficient e: ");
        	scanf("%d", &coE);
        	printf("Enter the value for coefficient f: ");
        	scanf("%d", &coF);
                                		// Giving the user the model of the equation with the order entered, and then prompting
                                		// the user for a value of each coefficient
    	}
     	if (functionOrder == 3){                       		
						// Checking if order is 3
        	printf("Following the model: cX^3 + dX^2 + eX + f\n");
        	printf("Enter the value for coefficient c: ");
        	scanf("%d", &coC);
        	printf("Enter the value for coefficient d: ");
        	scanf("%d", &coD);
        	printf("Enter the value for coefficient e: ");
        	scanf("%d", &coE);
        	printf("Enter the value for coefficient f: ");
        	scanf("%d", &coF);
                                		// Giving the user the model of the equation with the order entered, and then prompting
                                		// the user for a value of each coefficient
    	}
     	if (functionOrder == 2){                       		
						// Checking if order is 2
        	printf("Following the model: dX^2 + eX + f\n");
        	printf("Enter the value for coefficient d: ");
        	scanf("%d", &coD);
        	printf("Enter the value for coefficient e: ");
        	scanf("%d", &coE);
        	printf("Enter the value for coefficient f: ");
        	scanf("%d", &coF);
                                		// Giving the user the model of the equation with the order entered, and then prompting
                                		// the user for a value of each coefficient
    	}
     	if (functionOrder == 1){                       		
						// Checking if order is one
        	printf("Following the model: eX + f\n");
        	printf("Enter the value for coefficient e: ");
        	scanf("%d", &coE);
        	printf("Enter the value for coefficient f: ");
        	scanf("%d", &coF);
                                		// Giving the user the model of the equation with the order entered, and then prompting
                                		// the user for a value of each coefficient
    	}
    	printf("The functions range is now needed!\n");
    	printf("Please enter the minimum x value: ");
                                		// Prompting the user for the minimum value of the range
    	scanf("%f", &Xmin);
                                		// Allowing for user input
    	do {
        	printf("Please enter then maximum x value that is greater than the minimum value: ");
                                		// Prompting the user for the maximum value of the range
        	scanf("%f", &Xmax);
                                		// Allowing for user input
    	}
    	while (Xmax < Xmin || Xmin > Xmax);
                                		// Error checking that the minimum value is less than the max value and vice versa
    	dx = ((Xmax-Xmin)/10);
                                		// Calculating dx(a.k.a. the intervals with which x will vary)
    	maxCount =((Xmax-Xmin)/ dx);
                                		// Calculating the amount of times the function will be evaluated
    	for (i =0; i <= maxCount ; ++i){                       		
						// For loop designed to display function data
    		if (i == 0){
        	printf("\tx-values        y-values\n");
                                		// Table header
    		}
    	x = Xmin + dx*i;
                                		// Calculating x values
    	fx = ((coA*pow(x,5)) + (coB*pow(x,4)) + (coC*pow(x,3)) + (coD*pow(x,2)) + (coE*x + coF));
                                		// Calculating y values (f(x))
    	printf("\t%5.2f \t\t%5.2f\n",x, fx);
                                		// Printing the values to the user
    	}
    	return 0;
}	                           		// End of main function
