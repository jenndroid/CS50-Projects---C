/* Implements a dictionary's functionality */
//and https://stackoverflow.com/questions/32023260/inserting-a-node-in-a-hashtable lines 68, 75, 77, and 81-84

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "dictionary.h"

// Represents number of buckets in a hash table
#define N 26

// Represents a node in a hash table
//inside this node will be a data field, an array of chars called word
//also a pointer to a node struct this pointer is called next
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Represents a hash table- array of pointers to node
node *hashtable[N];

// Hashes word to a number between 0 and 25, inclusive, based on its first letter
unsigned int hash(const char *word)
{
    return tolower(word[0]) - 'a';
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Initialize all pointers in hash table to null
    for (int i = 0; i < N; i++)
    {
        hashtable[i] = NULL;
    }

    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        unload();
        return false;
    }

    // Buffer for a word
    char word[LENGTH + 1];

    // Insert words into hash table
    while (fscanf(file, "%s", word) != EOF)
    {
        //malloc space for a new node and create a pointer to it
        node* new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            unload();
            return false;
        }

        //insert word as value in node
        strcpy(new_node->word, word);
        new_node->next = NULL;

        //i think this gives the correct index for the hashed word does this need just 'word?'
        int j = hash(new_node->word);

        //jump to that hashtable bucket
        //check pointer in that bucket
        //if null change pointer in that bucket from null to pointing to current node
        //if not null make current node point to whatever hashtable bucket is pointing to
        //then go to hashtable bucket and change it to point to current node
        if (hashtable[j] == NULL)
        {
            hashtable[j] = new_node;
        }
        else
        {
           //remember this hashj is a pointer so line 83 gives you a pointer to a pointer
           new_node->next = hashtable[j];
           hashtable[j] = new_node;
        }

    }

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    int wordcount = 0;

    for(int i = 0; i < N; i++)
    {
        node *cursor = hashtable[i];

        while(cursor != NULL)
        {
            wordcount++;
            cursor = cursor->next;
        }
    }

    return wordcount;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{

   //create new pointer called node and have it point to first node of linked list the hashed word would be in
    node *cursor = hashtable[hash(word)];

    while(cursor != NULL)
    {
        int comparison = strcasecmp(word, cursor->word);

        if (comparison == 0)
        {
            //if strings are equal return true and break from loop as function has returned something
            return true;
        }
        else
        {
            cursor = cursor->next;

        }
    }

return false;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    int truthcount = 0;

    for (int i = 0; i < N; i++)
    {
        node *cursor = hashtable[i];

        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor -> next;
            free (temp);
        }

        truthcount++;
    }

if (truthcount == N)
{
    return true;
}

return false;
}


