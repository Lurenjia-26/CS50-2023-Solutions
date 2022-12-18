#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    int text = get_string("Text: ");
    int letters, words, sentences;
}

int count_letters(string text)
{
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if(isletter(text[i]))
            count++;
    }
}

int count_words(string text);
{

}

int count_sentences(string text)
{

}