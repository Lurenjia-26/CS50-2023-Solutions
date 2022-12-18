#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int cal_index(int letters, int words, int sentences);

int main(void)
{
    int letters, words, sentences;
    int index;
    double l, s;
    string text = get_string("Text: ");

    letters = count_letters(text);
    words = count_words(text);
    sentences = count_sentences(text);
    index = cal_index(letters, words, sentences);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
}

int count_letters(string text)
{
    int count = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalnum(text[i]))
        {
            count++;
        }
    }

    return count;
}

int count_words(string text)
{
    int count = 1;
    char pre_letter = ' ';

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalnum(text[i]) && isspace(pre_letter))
        {
            count++;
        }
        pre_letter = text[i];
    }

    return count;
}

int count_sentences(string text)
{
    int count = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }

    return count;
}

int cal_index(int letters, int words, int sentences)
{
    double l = (double)letters / (double)words * 100.0;
    double s = (double)sentences/ (double)words * 100.0;

    return (int)round(0.0588 * l - 0.296 * s - 15.8);
}