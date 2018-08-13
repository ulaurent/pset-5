// Implements a dictionary's functionality
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>


#include "dictionary.h"

typedef struct node         // node is now a data type
{
    char word[LENGTH + 1]; // An array of a given length plus 1, called word, of type char
    struct node *next;     // Introduce a node pointer called next
}
node;

node *HASH_TABLE[26];
unsigned int word_count = 0;


// Function used to hash word
int hash_word (const char *word)
{
    char index = (tolower(word[0]))- 'a';
    return index;

}


// Returns true if word is in dictionary else false
// The purpose of check is that if the word exist then you will be able to find it in the dictionary data structure
bool check(const char *word)
{   // In a hashtable dictionary, which bucket would the word be in? HASHTABLE[hash(word)]

    int head = hash_word(word);
   // node *head = HASH_TABLE[hash];

    // create a cursor that points to what head points to
    node *cursor = HASH_TABLE[head];

    while (cursor != NULL)
    {
        int i = strcasecmp( word, cursor -> word);
        // do something
        if(i == 0) // that means the two strings are equal to each other
        {
        return true;
        }
        cursor = cursor -> next;
    }

    return false;
}


// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    char word[LENGTH + 1];

    // Each index in the hashtable is of type node pointer
    FILE *file = fopen(dictionary,"r"); // introduces a pointer variable called file of type FILE

    if(file == NULL){
        fprintf(stderr, "FILE ERROR OPENING");
        return 1;
    }

    while(fscanf(file, "%s", word) != EOF)
    {
        // Introduce a new node pointer and allocate memory for that pointer
        node *new_node = malloc(sizeof(node));

        // Check if malloc succeded // If you run out of memory malloc returns NULL
        if (new_node == NULL)
        {
            unload();
            return false;
        }
        else
        {
        // Else malloc does not return NULL, continue...
        // Sets values for the node
        strcpy(new_node -> word, word);
        }

    // stored it in a variable called 'head' of type node pointer,
    // becuase each element in hashtable is of type node pointer already
    int head = hash_word(word);
    // initially head is NULL
    new_node -> next = HASH_TABLE[head];
    // Point Hash table indexed pointer to stored word
    HASH_TABLE[head] = new_node;
    word_count ++;
    }

    fclose(file);

    return true;
}






// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for(int head = 0; head <= 25; head++)
    {
        // create a cursor that points to what head points to
        node *cursor = HASH_TABLE[head];

        while(cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor -> next;
            free(temp);
            temp = cursor;
        }
    }

    // TODO
    return true;
}
