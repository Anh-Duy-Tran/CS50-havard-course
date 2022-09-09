#include <stdio.h>

int main(void){
	float n;
	int coin[4] = {25, 10, 5, 1};

	printf("Change owed: ");
	scanf("%f", &n);

	n = n * 100;
	int change;
	int count = 0;
	change = n / 1;

	for(int i = 0; i < 4; i++){
		while(change >= coin[i]){
			count++;
			change -= coin[i];
			printf("%i -> %i => %i \n", change + coin[i], change, coin[i]);
		}
	}
	printf("%i \n", count);


	return 0;
}
