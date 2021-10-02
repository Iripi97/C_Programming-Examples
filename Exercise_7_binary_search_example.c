#include <stdio.h>
int main(){
    	int b[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    	int key = 5;
    	int min = 0, max = 15;
    	int midPoint;
    	do {
        	midPoint = (max+min)/2;
        	if (b[midPoint] == key){
            		printf("Key found at element %d in the array", midPoint);
        	}
        	else if (b[midPoint] > key){
            		max = midPoint - 1;
        	}
        	else if (b[midPoint] < key){
            		min = midPoint +1 ;
		}
        }
        while ((b[midPoint] != key));
        return 0;
}
