#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    string key = "QWERTYUIOPASDFGHJKLZXCVBNM";
    if (strlen(key) != 26)
    {
        
    }
    string s = get_string("plaintext:  ");

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isalpha(s[i]))
        {
            if (isupper(s[i]))
            {
                s[i] = key[s[i] - 'a'];
            }
            else
            {
                s[i] = key[s[i] - 'A'];
            }
        }
    }

    printf("ciphertext: ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c", s[i]);
    }
}