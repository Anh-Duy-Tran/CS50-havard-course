#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(int argc, char *argv[]){

	if (argc < 2){
		printf("Usage ./ceasar key \n");
		return 1;
	}

	int key = 0;
	bool is_neg = false;
	for(int i = 0; argv[1][i] != '\0'; i++){
		if (argv[1][i] == '-')
			is_neg = true;
		else{
			if (isdigit(argv[1][i]))
				key = key * 10 + (int)argv[1][i] - (int)'0';
			else {
				printf("Usage ./ceasar key \n");
				return 2;
			}
		}
	}

	key = key % 25;

	if (is_neg){
		key *= -1;
		printf("ciphertext: ");
	}
	else
		printf("plaintext: ");

	char text[256];
	scanf ("%[^\n]%*c", text);


	bool is_upper;
	int index;
	for(int i = 0; text[i] != '\0'; i++){
		if(text[i] != ' '){
			is_upper = isupper(text[i]);

			index = (int)tolower(text[i]) - (int)'a';
			if (is_neg && -key > index)
				index += 25;
			index = (index + key) % 25;

			text[i] = (char)(index + (int)'a');

			if (is_upper)
				text[i] = toupper(text[i]);
		}
	}

	if (!is_neg)
		printf("ciphertext: ");
	else
		printf("plaintext: ");
	for(int i = 0; text[i] != '\0'; i++)
		printf("%c", text[i]);

	printf("\n");

	return 0;
}