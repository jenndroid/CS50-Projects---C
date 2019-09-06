/* Prints initials from a given name */
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

void get_initials(string s, int a);

int main(void)
{
    //get name from user and store its length in n
    string name = get_string();

    int n = strlen(name);

    get_initials(name, n);
}

void get_initials(string name, int n)
{

    //print first initial in upper case
    printf("%c", toupper(name[0]));

    //find & print any char after a space, in upper case
    for (int i = 0; i < n; i++)
        {
            if (name[i] == ' ')
            printf ("%c", toupper(name[i + 1]));
        }

    //go to new line
    printf("\n");
}



