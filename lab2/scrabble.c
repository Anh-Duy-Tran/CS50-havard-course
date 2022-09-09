#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(char word[]);

int main(void)
{
    // Get input words from both players
    char word1[256], word2[256];
    printf("Player 1: ");
    scanf("%s", word1);
    printf("Player 2: ");
    scanf("%s", word2);
    printf("\n");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    printf("player 1 score: %i\n", score1);
    printf("player 2 score: %i\n", score2);
    printf("\n");

    if (score1 > score2)
    	printf("PLAYER 1 WINS !!\n");
    else
    	if (score1 > score2)
    		printf("PLAYER 2 WINS !!\n");
    	else
    		printf("TIE\n");

}

int compute_score(char word[])
{
	int score = 0;
    for(int i = 0; word[i] != '\0'; i++){
    	word[i] = toupper(word[i]);
    	if (word[i] >= 'A' && word[i] <= 'Z')
    		score += POINTS[word[i] - 'A'];
    }
    return score;
}
