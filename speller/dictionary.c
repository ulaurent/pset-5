// Implements a dictionary's functionality
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "dictionary.h"

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    printf("here: %s",word);
    // TODO
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    typedef struct node         // node is now a data type
    {
        char word[LENGTH + 1]; // An array of a given length plus 1, called word, of type char
        struct node *next;     // Introduce a node pointer called next
    }
    node;

    char word[LENGTH + 1];

    node *HASHTABLE[27]; //An array of node pointers called HASHTABLE //of type node pointer

    // Each index in the hashtable is of type node pointer
    FILE *file = fopen(dictionary,"r"); // introduces a pointer variable called file of type FILE

    if(file == NULL){
        fprintf(stderr, "FILE ERROR OPENING");
        return 1;
    }

    while(fscanf(file, "%s", word) != EOF)
    {
        // Hash function // Hash the word
        int letter = word[0] - 'a';
        // stored it in a variable called 'head' of type node pointer,
        // becuase each element in hashtable is of type node pointer already
        node *head = HASHTABLE[letter];

        // Introduce a new node pointer and allocate memory for that pointer
        node *new_node = malloc(sizeof(node));

        // Check if malloc succeded // If you run out of memory malloc returns NULL
        if (new_node == NULL)
        {
            unload();
            return false;
        }

        // Else malloc does not return NULL, continue...
        // Sets values for the node
        strcpy(new_node -> word, word);

        // initially head is NULL
        new_node -> next = head;

        // Point Hash table indexed pointer to stored word
        head = new_node;
    }

    fclose(file);

    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    return false;
}
