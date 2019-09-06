/* Encrypts a string using the Vigenere cipher */

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void encipher_v(string s, string t, int a, int b);

int main(int argc, string argv[])
{
    //only run if argc == 2
    if (argc == 2)
    {
        //store argv[1] as variable keyword
        string keyword = argv[1];

        //store length of keyword in key_leng
        int key_leng = strlen(keyword);

        //check each char of keyword argv[1] and only proceed if all are alpha chars
        for (int z = 0; z < key_leng; z++)
        {
            if (isdigit(keyword[z]))
            {
                printf("Keyword of letters only please\n");
                return 1;
            }
        }

        //prompt user for plaintext and store in variable plntxt
        printf("plaintext: ");
        string plntxt = get_string();

        //store length of plntxt in p_leng
        int p_leng = strlen(plntxt);

        encipher_v(plntxt, keyword, p_leng, key_leng);

        //print new line
        printf ("\n");

        //return cool exit code
        return 0;
    }
    else
    {
        printf("Usage: ./filename keyword\n");
        return 1;
    }
}

void encipher_v(string plntxt, string keyword, int p_leng, int key_leng)
{
        //get ready to encipher!
        for (int i = 0, j = 0; i < p_leng; i++)
        {
            if (j == key_leng)
            {
                j = 0;
            }

            if (isalpha(plntxt[i]))
            {
                if (islower(plntxt[i]))
                {
                    int k = tolower(keyword[j]);
                    int c = (plntxt[i] + (k - 97));

                if (c > 122)
                {
                    int d = c - 26;
                    printf("%c", d);
                }
                    else if (c < 122)
                {
                    printf("%c", c);
                }
                    j++;
                }

                else if (isupper(plntxt[i]))
                {
                    int k = toupper(keyword[j]);
                    int c = (plntxt[i] + (k - 65));

                    if (c > 90)
                        {
                            int d = c - 26;
                            printf("%c", d);
                        }
                    else if (c < 90)
                        {
                            printf("%c", c);
                        }
                    j++;
                }
            }
            else
            {
                printf("%c", (plntxt[i]));
            }
        }
}
