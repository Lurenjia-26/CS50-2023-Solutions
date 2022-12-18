#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    int letters, words, sentences;
    string text = get_string("Text: ");

    letters = count_letters(text);
    printf("%d letters\n", letters);
}

int count_letters(string text)
{
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if(isalnum(text[i]))
            count++;
    }
    return count;
}

int count_words(string text)
{
    int count = 0;

    return count;
}

int count_sentences(string text)
{
    int count = 0;

    return count;
}