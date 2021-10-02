#include <stdio.h>

int main(){
	int i,swap,temp;
    	int b[] = {4,56,234,5,2,3,5,23,3,54,4,12,1,6,3,3};
    	do {
        	swap = 0;
        	for (i = 0; i < 15; i++){
            		if (b[i] > b[i+1]){
                		swap++;
                		temp = b[i];
                		b[i] = b[i+1];
                		b[i+1] = temp;
            		}
        	}
    	}
    	while (swap != 0);
        for (i = 0; i < 16; i++){
            	printf("%d\n", b[i]);
        }
}
