#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(int argc, char *argv[]){

	if (argc < 2){
		printf("Usage ./substitution key \n");
		return 1;
	}

	int key[26], count = 0;
	for(int i = 0; argv[1][i] != '\0'; i++){
		key[i] = (int)toupper(argv[1][i]) - 'A';
		count++;
	}
	if (count != 26){
		printf("Key must contain 26 characters. \n");
		printf("%d", count);
		return 2;
	}

	char text[256];
	int index;
	bool is_upper;
	printf("plaintext: ");
	scanf ("%[^\n]%*c", text);

	for(int i = 0; text[i] != '\0'; i++){
		if (isalpha(text[i])) {
			is_upper = isupper(text[i]);
			text[i] = tolower(text[i]);
			index = key[(int) text[i] - (int)'a'];

			text[i] = (char)(index + 'a');
			if (is_upper)
				text[i] = toupper(text[i]);
		}
	}


	printf("ciphertext: ");
	for(int i = 0; text[i] != '\0'; i++){
		printf("%c", text[i]);
	}
	printf("\n");
}