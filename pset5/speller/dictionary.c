// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    bool end_word;
    struct node *next[27];
}
node;

//Roots of Tries
node *root_s, *root_l;

//Size of Trie
unsigned dict_size = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(char word)
{
    // TODO: Improve this hash function
    if (word == '\'')
    {

    }
    return 26;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *dict_s = fopen("dictionaries/large", "r");
    FILE *dict_l = fopen("dictionaries/small", "r");
    if (dict_l == NULL || dict_s == NULL)
    {
        return false;
    }
    root_s = malloc(sizeof(node));
    root_l = malloc(sizeof(node));
    node *cur_s = root_s;
    node *cur_l = root_l;

    char ch;
    while ((ch = fgetc(dict_s)) != EOF)
    {
        if (ch == '\n')
        {
            cur_s->end_word = true;
            cur_s = root_s;
            dict_size++;
        }
        else
        {
            unsigned i = hash(ch);
            if (cur_s->next[i] == NULL)
            {
                cur_s->next[i] = malloc(sizeof(node));
            }
            cur_s = cur_s->next[i];
        }
    }

    fclose(dict_s);
    fclose(dict_l);
    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
