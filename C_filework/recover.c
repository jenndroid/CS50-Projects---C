//reads card.raw and writes jpegs to files

#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: recover filename.type\n");
        return 1;
    }

    // remember filename
    char *infile = argv[1];

    //open infile correctly; return 2 if not ok
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    //create buffer array of 512 bytes
    BYTE buffer[512];

    //create counter for labelling jpegs as they are created
    int jpgctr = 0;

    //create string to put jpeg name into with sprintf
    char jpgname[8];

    //read 512 bytes into buffer until EOF
    while (fread(buffer, sizeof(BYTE), 512, inptr) == 512)
    {
        //when you find signature
        while (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
        //open a new outfile with a new name, write block, move to next
        jpgctr++ ;
        sprintf(jpgname, "%03i.jpg", jpgctr);

        FILE *outptr = fopen(jpgname, "w");
        if (outptr == NULL)
        {
        fclose(inptr);
        fprintf(stderr, "Could not open outfile\n");
        return 3;
        }

        //I am copying this line but idky it's not buffer, sizeofBYTE, 512, outptr. idg this function rly
        fwrite(buffer, 512, 1, outptr);
        fread(buffer, sizeof(BYTE), 512, inptr);

            //if not sig. write block to current outfile
            while (buffer[0] != 0xff || buffer[1] != 0xd8 || buffer[2] != 0xff || (buffer[3] & 0xf0) != 0xe0)
            {
            fwrite(buffer, 512, 1, outptr);
            fread(buffer, sizeof(BYTE), 512, inptr);
            }

        //close current outfile because when you get back to top you will need to make a new one
        fclose(outptr);
        }

    }

    //now we are done with infile and outfile so close both
    fclose(inptr);

    return 0;
}