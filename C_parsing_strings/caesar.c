/* Encrypts a string using the Caesar cipher */

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void encipher_c(string s, int a, int b);

int main(int argc, string argv[])
{
    //only run if there is one arg after filename
    if (argc == 2)
    {
        //convert second string in command line to an int
        int k = atoi(argv[1]);

        //prompt user for plaintext
        printf("plaintext: ");
        string plntxt = get_string();

        //store string length in n
        int n = strlen(plntxt);

        //print to screen 'ciphertext' before calculating that below
        printf("ciphertext: ");

        //now to encipher text:

        encipher_c(plntxt, n, k);

        //print a newline after outputting enciphered text
        printf("\n");

        //return exit code 0 as program has run as it should
        return 0;
    }

    //if argc != 2 print appropriate input request and return exit code 1
    else
    {
        printf("One command line argument, please!\n");
        return 1;
    }
}

void encipher_c(string plntxt, int n, int k)
{
    //iterate over chars in plntxt
        for (int j = 0; j < n; j++)
        {
            //deal with uppercase letters first
            if (isupper(plntxt[j]))
            {
            int c = ((plntxt[j] + k) - 65)  % 26 + 65;
            printf("%c", c);
            }

            //and then lowercase
            else if (islower(plntxt[j]))
            {
            int c = ((plntxt[j] + k) - 97) % 26 + 97;
            printf("%c", c);
            }

            //and then whitespace
            else if (isspace(plntxt[j]))
            {
            printf(" ");
            }

            //and then punctuation
            else if (ispunct(plntxt[j]))
            {
            printf("%c", plntxt[j]);
            }
        }
}