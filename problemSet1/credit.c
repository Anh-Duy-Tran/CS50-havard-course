#include <stdio.h>

int main(void){
	long n;
	scanf("%li", &n);
	
	int buffer[2] = {0, 0};
	int doubledSum = 0;
	int otherSum = 0;
	int count = 0;
	int digits;

	while(n != 0){
		if(count % 2 == 0)
			otherSum += n % 10;
		else
		{
			digits = 2 * (n % 10);
			while(digits != 0)
			{
				doubledSum += digits % 10;
				digits /= 10;
			}	
		}
		buffer[1] = buffer[0];
		buffer[0] = n % 10;
		n = n / 10;
		count++;
	}

	if ((doubledSum + otherSum) % 10 == 0)
		if (buffer[0] == 4)
			printf("VISA");
	else
		printf("WRONG NUMBER!\n");
}