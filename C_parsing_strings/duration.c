/* Finds duration of a note from eighths */

#include <cs50.h>
#include <stdio.h>
#include <string.h>


int main(void)
{
//get string which is actually a fraction
string fraction = get_string();

//split the string-array- into chars and cast numerator and denominator as separate ints
float x = atoi(&fraction[0]);
int y = atoi(&fraction[2]);

//attempt some arithmetic on that
int duration = x / y * 8;

//print result of attempt
printf("%i\n", duration);

}




