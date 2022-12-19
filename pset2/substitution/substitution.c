#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    string key = argv[1];

    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    string s = get_string("plaintext:  ");

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isalpha(s[i]))
        {
            if (islower(s[i]))
            {
                s[i] = tolower(key[tolower(s[i]) - 'a']);
            }
            else
            {
                s[i] = toupper(key[toupper(s[i]) - 'A']);
            }
        }
    }

    printf("ciphertext: %s\n", s);
}
