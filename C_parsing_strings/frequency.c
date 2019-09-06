/* Calculates the frequency in hertz of a given note */

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{//main
//declare int n, to be found with this program
int n = 0;

float frequency;

//take input note as string
printf("Which note are you looking for?\n");
string note_wanted = get_string();

//check length of this string
int length = strlen(note_wanted);

//first conditional branch, depending on string length:
//if length is three according to strleng- note has accidental- take this branch
    if (length == 3)
    {//if three notes
    //examine octave number, element 2, first:
    //to examine, change the contents of this element from char to int first
    int sharpoctave = (note_wanted[2] - 48);

    //second conditional branch, depending on whether this ocatve is lower or higher than 4
    if (sharpoctave < 4) //if the number is less than 4
    {
        //for every difference of 1 in octave number, minus 12 from n
        for (int i = 3; i >= sharpoctave; i--)
        {
            n = n - 12;
        }

        //then deal with the letter
        if (note_wanted[0] == 65)// if A
        {
            n = n + 0;
        }
        else if (note_wanted[0] == 66)//if B
        {
            n = n + 2;
        }
        else if (note_wanted[0] == 67)//if C
        {
            n = n - 9;
        }
        else if (note_wanted[0] == 68)//if D
        {
            n = n - 7;
        }
        else if (note_wanted[0] == 69)// if E
        {
            n = n - 5;
        }
        else if (note_wanted[0] == 70)// if F
        {
            n = n - 4;
        }
        else if(note_wanted[0] == 71)// if G
        {
            n = n - 2;
        }

        //finally for the accidental
        if (note_wanted[1] == 35)// for a sharp
        {
            n = n + 1;
        }
        else if (note_wanted[1] == 98)//flat
        {
            n = n - 1;
        }
        printf("n = %i\n", n);

        //new branch- if three elements long but octave of 4
        }
        else if (sharpoctave == 4)//sharpoctave is 4
        {
           n = 0;

        //then deal with the letter
        if (note_wanted[0] == 65)
        {
            n = n + 0;
        }
        else if (note_wanted[0] == 66)
        {
            n = n + 2;
        }
        else if (note_wanted[0] == 67)
        {
            n = n - 9;
        }
        else if (note_wanted[0] == 68)
        {
            n = n - 7;
        }
        else if (note_wanted[0] == 69)
        {
            n = n - 5;
        }
        else if (note_wanted[0] == 70)
        {
            n = n - 4;
        }
        else if (note_wanted[0] == 71)
        {
            n = n - 2;
        }

        //and finally for the accidental
        if (note_wanted[1] == 35)//if sharp
        {
            n = n + 1;
        }
        else if (note_wanted[1] == 98)//a flat
        {
            n = n - 1;
        }
        printf("n = %i\n", n);
        }
        //new branch- three elements and octave higher than 4

        if (sharpoctave > 4)//sharpoctave is more than 4
        {
        //for every difference of 1, add 12 to n.
        for (int i = 5; i <= sharpoctave; i++)
        {
            n = n + 12;
        }

        // then deal with letter
        if (note_wanted[0] == 65)// if A
        {
            n = n + 0;
        }
        else if (note_wanted[0] == 66)//if B
        {
            n = n + 2;
        }
        else if (note_wanted[0] == 67)//if C
        {
            n = n - 9;
        }
        else if (note_wanted[0] == 68)//if D
        {
            n = n - 7;
        }
        else if (note_wanted[0] == 69)// if E
        {
            n = n - 5;
        }
        else if (note_wanted[0] == 70)// if F
        {
            n = n - 4;
        }
        else if(note_wanted[0] == 71)// if G
        {
            n = n - 2;
        }

        // and for accidental minus 1
        if (note_wanted[1] == 35)
        {
            n = n + 1;
        }
        else if (note_wanted[1] == 98)
        {
            n = n - 1;
        }
        printf("n = %i\n", n);
        }

    }

    else if (length == 2) //if length is two according to strleng- take this branch
    {

    //examine the number first
    //in order to do this, convert from char to int
    int plainoctave = (note_wanted[1] - 48);

    //conditional branch depending on whether this number is less or more than four
    if (plainoctave < 4) //if it's less than 4
    {
        //for every difference of 1, add 12 to n
        for (int i = 3; i >= plainoctave; i--)
        {
            n = n - 12;
        }

        // then deal with letter
        if (note_wanted[0] == 65)// if A
        {
            n = n + 0;
        }
        else if (note_wanted[0] == 66)//if B
        {
            n = n + 2;
        }
        else if (note_wanted[0] == 67)//if C
        {
            n = n - 9;
        }
        else if (note_wanted[0] == 68)//if D
        {
            n = n - 7;
        }
        else if (note_wanted[0] == 69)// if E
        {
            n = n - 5;
        }
        else if (note_wanted[0] == 70)// if F
        {
            n = n - 4;
        }
        else if(note_wanted[0] == 71)// if G
        {
            n = n - 2;
        }
        printf("n = %i\n", n);
        }

    if (plainoctave == 4)
    {
        //if the number is 4:
        //add nothing
        n = 0;

        //then deal with the letter
        if (note_wanted[0] == 65)
        {
            n = n + 0;
        }
        else if (note_wanted[0] == 66)
        {
            n = n + 2;
        }
        else if (note_wanted[0] == 67)
        {
            n = n - 9;
        }
        else if (note_wanted[0] == 68)
        {
            n = n - 7;
        }
        else if (note_wanted[0] == 69)
        {
            n = n - 5;
        }
        else if (note_wanted[0] == 70)
        {
            n = n - 4;
        }
        else if (note_wanted[0] == 71)
        {
            n = n - 2;
        }
        printf("n = %i\n", n);
    }
    else if (plainoctave > 4)
    {
        //if the number is more than 4:
        //for every difference of 1, add 12 to n.
        for (int i = 5; i <= plainoctave; i++)
        {
            n = n + 12;
        }

        //then deal with the letter
        if (note_wanted[0] == 65)
        {
            n = n + 0;
        }
        else if (note_wanted[0] == 66)
        {
            n = n + 2;
        }
        else if (note_wanted[0] == 67)
        {
            n = n - 9;
        }
        else if (note_wanted[0] == 68)
        {
            n = n - 7;
        }
        else if (note_wanted[0] == 69)
        {
            n = n - 5;
        }
        else if (note_wanted[0] == 70)
        {
            n = n - 4;
        }
        else if (note_wanted[0] == 71)
        {
            n = n - 2;
        }
        printf("n = %i\n", n);
    }
    }

    //now for the actual formula
    if (n < 0)
    {
    n = (n * -1); //make n a positive number for the formula
    double x = (n / -12.0); //double for accuracy, 12.0 to match so both floats
    float y = pow(2, x); //2 to the power of n/-12, as a float
    frequency = (y * 440.00); //multiply those two floats to get frequency
    printf("frequency is %.2f\n", frequency);
    }
    else if (n == 0)
    {
    double x = (n / -12.0);
    float y = pow(2, x);
    frequency = (y * 440.00);
    printf("frequency is %.2f\n", frequency);
    }
    else if (n > 0)
    {
    double x = (n / 12.0);
    float y = pow(2, x);
    frequency = (y * 440);
    printf("frequency is %.2f\n", frequency);
    }
}
