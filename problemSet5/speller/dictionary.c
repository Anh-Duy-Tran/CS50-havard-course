// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <math.h>
#include "dictionary.h"


// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;
// Number of buckets in hash table

const unsigned int level = 5;

const unsigned int N = 26*26*26*26*26 + 1;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    //TODO

    unsigned int hashed = hash(word);
    // printf("the word %s has been hashed to: %i\n", word, hashed);
    // printf("the words in the %i dict location: \n", hashed);
    // for(node *tmp = table[hashed]; tmp != NULL; tmp = tmp->next){
    //     printf("%i : %s\n", strcasecmp(word, tmp->word), tmp->word);
    // }
    //printf("\n");

    node *tmp = table[hashed];  
    while(tmp != NULL){
        if (strcasecmp(word, tmp->word) == 0)
            {
                //printf("found    %s\n", tmp->word);
                return true;

            }
        else   
            tmp = tmp->next;
    }

    return false;
}


// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    unsigned int hashed = 0;

    for(int i = 0; isalnum(word[i]) && i < level; i++){
        unsigned int value = tolower(word[i]) - 'a';

        hashed = hashed * 26 + value;
    }

    return hashed;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO

    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL){
        return false;
    }

    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    char buffer[LENGTH+1];

    while (fscanf(dict,"%s",buffer)!=EOF)
        {   
            unsigned int hashed = hash(buffer);

            node *n = malloc(sizeof(node));
            if (n == NULL)
                return false;
            
            strcpy(n->word, buffer);
            
            n->next = table[hashed];

            table[hashed] = n;
        }

    // close the file
    fclose(dict);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO

    int count = 0;

    for (int i = 0; i < N; i++)
    {
        node* tmp = table[i];
        while(tmp != NULL)
        {
            count++;
            tmp = tmp->next;
        }
    }

    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO

    for (int i = 0; i < N; i++)
    {
        node* crr = table[i];
        if (crr == NULL)
            continue;
        node* tmp = table[i]->next;

        while (tmp != NULL)
        {
            free(crr);
            crr = tmp;
            tmp = tmp->next;
        }
        free(crr);   
    }

    return true;
}
