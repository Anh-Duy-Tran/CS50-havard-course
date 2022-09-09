#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int get_number_of_voter(void){
	int n;
	do {
		printf("Enter number of voter: ");
		scanf("%d", &n);
	} while (n <= 0);
	return n;
}

int main(int argc, char *argv[]){

	if (argc < 2){
		printf("Usage ./plurality people names\n");
		return 1;
	}

	int count[argc];
	for (int i = 0; i < argc; i++)
		count[i] = 0;
	int currentMax = -1;

	int number;
	number = get_number_of_voter();

	bool found = false;
	char votedName[256];
	for(int i = 0; i < number; i++){
		found = false;
		while (!found){	
			printf("Voter number %d voted for: ", i + 1);
			scanf("%s", votedName);
			for(int j = 1; j < argc; j++)
			if (strcmp(votedName, argv[j]) == 0)
			{
				found = true;
				count[j]++;
				if (count[j] > currentMax)
					currentMax = count[j];
				break;
			}
			if (!found) {
				printf("Invalid vote.\n");
			}
		}
	}

	printf("The Winner Is: ");

	for (int i = 1; i < argc; i++){
		if (count[i] == currentMax)
			printf("%s ", argv[i]);
	}

	printf("\n");
}
