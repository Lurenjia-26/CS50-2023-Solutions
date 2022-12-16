#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("What's your name?\n"); //get one's name
    printf("Hello, %s!\n", name); //say hello
    return 0;
}