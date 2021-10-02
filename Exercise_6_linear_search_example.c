#include <stdio.h>
int main(){
	int b[] = {1,2,3,4,5,6,7,8,9,0};
    	int key = 0;
    	int index;
    	for (index = 0; index < 10; index++){
        	if (b[index] == key)
            		printf("Found at element %d in the array.", index);
    	}
        return 0;
}
