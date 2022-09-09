//index = 0.0588 * L - 0.296 * S - 15.8

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char** argv) {
	char text[500];
	
	int numOfLetters = 0;
	int numOfWords = 1;
	int numOfSentences = 0;

	scanf("%[^\n]%*c", text);

	for(int i = 0; text[i] != '\0'; i++){
		text[i] = toupper(text[i]);
		if (text[i] >= 'A' && text[i] <= 'Z')
			numOfLetters++;
		else
			if (text[i] == ' ')
				numOfWords++;
			else
				if (text[i] == '.' || text[i] == '!')
					numOfSentences++;
	}

	float L = ((float) numOfLetters / (float) numOfWords) * (float) 100;
	float S = ((float) numOfSentences / (float) numOfWords) * (float) 100;

	float index = 0.0588 * L - 0.296 * S - 15.8;

	printf("\n");
	printf("number of letters in text: %d\n", numOfLetters);
	printf("number of words in text: %d\n", numOfWords);
	printf("number of sentence in text: %d\n", numOfSentences);

	printf("\n");
	printf("Letter per 100 words: %f\n", L);
	printf("Sentence per 100 words: %f\n\n", S);

	printf("index: %d\n", (int)round(index));

}
