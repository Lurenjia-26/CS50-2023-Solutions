#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 == score2)
    {
        printf("Tie!\n");
    }
    else
    {
        printf("Player %d wins!\n", score1 > score2 ? score1 : score2);
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int score = 0;

    for (int i = 0; word[i] != '\0'; i++)
    {
        switch (tolower(word[i]))
        {
        case 'a':
            sum += POINTS[0];
            break;
        case 'b':
            sum += POINTS[1];
            break;
        case 'c':
            sum += POINTS[2];
            break;
        case 'd':
            sum += POINTS[3];
            break;
        case 'e':
            sum += POINTS[4];
            break;
        case 'f':
            sum += POINTS[5];
            break;
        case 'g':
            sum += POINTS[6];
            break;
        case 'h':
            sum += POINTS[7];
            break;
        case 'i':
            sum += POINTS[8];
            break;
        case 'j':
            sum += POINTS[9];
            break;
        case 'k':
            sum += POINTS[10];
            break;
        case 'l':
            sum += POINTS[11];
            break;
        case 'm':
            sum += POINTS[12];
            break;
        case 'n':
            sum += POINTS[13];
            break;
        case 'o':
            sum += POINTS[14];
            break;
        case 'p':
            sum += POINTS[15];
            break;
        case 'q':
            sum += POINTS[16];
            break;
        case 'r':
            sum += POINTS[17];
            break;
        case 's':
            sum += POINTS[18];
            break;
        case 't':
            sum += POINTS[19];
            break;
        case 'u':
            sum += POINTS[20];
            break;
        case 'v':
            sum += POINTS[21];
            break;
        case 'w':
            sum += POINTS[22];
            break;
        case 'x':
            sum += POINTS[23];
            break;
        case 'y':
            sum += POINTS[24];
            break;
        case 'z':
            sum += POINTS[25];
            break;
        }
    }
    return score;
}
